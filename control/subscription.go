package control

import (
	"errors"

	apimodel "gerrit.o-ran-sc.org/r/ric-plt/xapp-frame/pkg/clientmodel"
	"gerrit.o-ran-sc.org/r/ric-plt/xapp-frame/pkg/xapp"
)

var (
	HTTPPort            int64  = 8080
	RMRPort             int64  = 4560
	Host                string = "service-ricxapp-kpm-http.ricxapp"
	ReportPeriod        int64  = 1
	XappEventInstanceID int64  = 0
	ActionTypeReport    string = "report"
	GranulPeriod        uint64 = 1
)

func GetClientEndPoint() *apimodel.SubscriptionParamsClientEndpoint {
	ClientEndpoint := apimodel.SubscriptionParamsClientEndpoint{
		HTTPPort: &HTTPPort,
		Host:     Host,
		RMRPort:  &RMRPort,
	}
	return &ClientEndpoint
}

func GenerateEventTriggerDefinition() (EventTriggerDefinition []int64, err error) {
	e2sm := &E2sm{}
	Buffer := make([]byte, 100)

	NewBuffer, err := e2sm.EventTriggerDefinitionEncode(Buffer, ReportPeriod)
	if err != nil {
		return make([]int64, 0), err
	}
	EventTriggerDefinition = ByteSlice2Int64Slice(NewBuffer)
	return EventTriggerDefinition, nil
}

func ParsemeasInfoList(measInfoActionList []MeasurementInfo_Action_Item) (measInfoList []MeasurementInfoItem, err error) {
	if len(measInfoActionList) == 0 {
		return make([]MeasurementInfoItem, 0), errors.New("There is no information in measInfo_Action_List")
	}

	measInfoList = []MeasurementInfoItem{}

	for i := 0; i < len(measInfoActionList); i++ {
		measName := PrintableString{
			Buf:  measInfoActionList[i].measName.Buf,
			Size: measInfoActionList[i].measName.Size,
		}
		measInfoItem := MeasurementInfoItem{
			measType:      measName,
			labelInfoList: []LabelInfoItem{},
		}

		measInfoList = append(measInfoList, measInfoItem)
	}

	if len(measInfoList) == 0 {
		return make([]MeasurementInfoItem, 0), errors.New("Failed to parse measInfo_Action_List")
	}

	return measInfoList, nil
}

func ParsemeasCondList(measInfoActionList []MeasurementInfo_Action_Item) (measCondList []MeasurementCondItem, err error) {
	if len(measInfoActionList) == 0 {
		return make([]MeasurementCondItem, 0), errors.New("There is no information in measInfo_Action_List")
	}

	measCondList = []MeasurementCondItem{}

	for i := 0; i < len(measInfoActionList); i++ {
		measName := PrintableString{
			Buf:  measInfoActionList[i].measName.Buf,
			Size: measInfoActionList[i].measName.Size,
		}
		measCondItem := MeasurementCondItem{
			measType:     measName,
			matchingCond: []MatchingCondItem{},
		}

		measCondList = append(measCondList, measCondItem)
	}

	if len(measCondList) == 0 {
		return make([]MeasurementCondItem, 0), errors.New("Failed to parse measInfo_Action_List")
	}
	return measCondList, nil
}

func ParseCQI(RanName string) (CellGlobalId *CGI) {
	/** Just Skip because RIC platform hasn't supported the feature **/
	/*
		nodebInfor, err := xapp.Rnib.GetNodeb(RanName)
		if err != nil {
			xapp.Logger.Error("Failed to get NodebInfor for %s, error: %v", RanName, err)
		}

		//Check gNB, NodeBType = 2 means gNB
		if nodebInfor.NodeType == 2 {
			NrCellList := nodebInfor.GetGnb().GetServedNrCells()
			if len(NrCellList) == 0 {
				xapp.Logger.Debug("NrCellList is empty")
				return nil
			}
			NrCellInfor := NrCellList[0].GetServedNrCellInformation()

			xapp.Logger.Debug("NrCellInfor is %v", NrCellInfor)
			pLMNIdentitys := NrCellInfor.GetServedPlmns()
			if len(pLMNIdentitys) == 0 {
				xapp.Logger.Debug("pLMNIdentitys is empty")
				return nil
			}

			CellGlobalId.pLMNIdentity = pLMNIdentitys[0]
			CellGlobalId.CellIdentity = NrCellInfor.GetCellId()
			CellGlobalId.NodebType = 2

			return CellGlobalId
		} else {
			xapp.Logger.Debug("KPM xApp doesn't support eNB %s", nodebInfor.RanName)
			return nil

		}
	*/

	/* Here just hard core */
	CellGlobalId = &CGI{
		pLMNIdentity: "001F01",
		CellIdentity: "000100100011010001010110000000000001",
		NodebType:    2,
	}

	return CellGlobalId
}

func GenerateActionDefinitionFormat1(RanName string, ReportStyleItem RIC_ReportStyle_Item) (ActionDefinition []byte, err error) {
	// If the coded length is too long, it needs to enlarge the buffer
	Buffer := make([]byte, 5000)

	MeasInfoList, err := ParsemeasInfoList(ReportStyleItem.measInfo_Action_List)
	if err != nil {
		return make([]byte, 0), err
	}

	//Parse CGI
	CGI := ParseCQI(RanName)

	ActionDefinitionFormat1 := E2SM_KPM_ActionDefinition_Format1{
		measInfoList: MeasInfoList,
		granulPeriod: GranulPeriod,
		cellGlobalID: CGI,
	}

	e2sm := &E2sm{}
	ActionDefinition, err = e2sm.ActionDefinitionFormat1Encode(Buffer, ActionDefinitionFormat1)
	return ActionDefinition, err
}

func GenerateActionDefinitionFormat3(RanName string, ReportStyleItem RIC_ReportStyle_Item) (ActionDefinition []byte, err error) {
	// If the coded length is too long, it needs to enlarge the buffer
	Buffer := make([]byte, 5000)

	//Parse Measurement Condition List
	MeasCondList, err := ParsemeasCondList(ReportStyleItem.measInfo_Action_List)
	if err != nil {
		return make([]byte, 0), err
	}

	//Parse CGI
	CGI := ParseCQI(RanName)

	ActionDefinitionFormat3 := E2SM_KPM_ActionDefinition_Format3{
		measCondList: MeasCondList,
		granulPeriod: GranulPeriod,
		cellGlobalID: CGI,
	}

	e2sm := &E2sm{}
	ActionDefinition, err = e2sm.ActionDefinitionFormat3Encode(Buffer, ActionDefinitionFormat3)
	return ActionDefinition, err
}

func ActionDefinitionFormat1EncodedByte() (ActionDefinitionFormat1 []int64) {
	//Support VIAVI RIC Test v1.5
	ActionDefinitionFormat1 = []int64{0, 1, 1, 8, 0, 42, 0, 80, 78, 82, 45, 67, 71, 73, 1, 32, 0, 0, 0, 80, 78, 82, 45, 80, 67, 73, 1, 32, 0, 0, 0, 128, 71, 78, 66, 45, 68, 85, 45, 73, 68, 1, 32, 0, 0, 0, 160, 68, 82, 66, 46, 85, 69, 84, 104, 112, 68, 108, 1, 32, 0, 0, 0, 160, 68, 82, 66, 46, 85, 69, 84, 104, 112, 85, 108, 1, 32, 0, 0, 1, 96, 81, 111, 115, 70, 108, 111, 119, 46, 80, 100, 99, 112, 80, 100, 117, 86, 111, 108, 117, 109, 101, 85, 108, 1, 32, 0, 0, 1, 96, 81, 111, 115, 70, 108, 111, 119, 46, 80, 100, 99, 112, 80, 100, 117, 86, 111, 108, 117, 109, 101, 68, 108, 1, 32, 0, 0, 0, 176, 82, 82, 67, 46, 67, 111, 110, 110, 77, 101, 97, 110, 1, 32, 0, 0, 0, 160, 82, 82, 67, 46, 67, 111, 110, 110, 77, 97, 120, 1, 32, 0, 0, 1, 48, 82, 82, 67, 46, 73, 110, 97, 99, 116, 105, 118, 101, 67, 111, 110, 110, 77, 101, 97, 110, 1, 32, 0, 0, 1, 32, 82, 82, 67, 46, 73, 110, 97, 99, 116, 105, 118, 101, 67, 111, 110, 110, 77, 97, 120, 1, 32, 0, 0, 0, 208, 82, 82, 85, 46, 80, 114, 98, 65, 118, 97, 105, 108, 68, 108, 1, 32, 0, 0, 0, 208, 82, 82, 85, 46, 80, 114, 98, 65, 118, 97, 105, 108, 85, 108, 1, 32, 0, 0, 0, 192, 82, 82, 85, 46, 80, 114, 98, 85, 115, 101, 100, 68, 108, 1, 32, 0, 0, 0, 192, 82, 82, 85, 46, 80, 114, 98, 85, 115, 101, 100, 85, 108, 1, 32, 0, 0, 1, 96, 84, 66, 46, 84, 111, 116, 78, 98, 114, 68, 108, 73, 110, 105, 116, 105, 97, 108, 46, 81, 112, 115, 107, 1, 32, 0, 0, 1, 112, 84, 66, 46, 84, 111, 116, 78, 98, 114, 68, 108, 73, 110, 105, 116, 105, 97, 108, 46, 49, 54, 81, 97, 109, 1, 32, 0, 0, 1, 112, 84, 66, 46, 84, 111, 116, 78, 98, 114, 68, 108, 73, 110, 105, 116, 105, 97, 108, 46, 54, 52, 81, 97, 109, 1, 32, 0, 0, 1, 128, 84, 66, 46, 84, 111, 116, 78, 98, 114, 68, 108, 73, 110, 105, 116, 105, 97, 108, 46, 50, 53, 54, 81, 97, 109, 1, 32, 0, 0, 1, 0, 84, 66, 46, 73, 110, 116, 105, 97, 108, 69, 114, 114, 78, 98, 114, 68, 108, 1, 32, 0, 0, 1, 80, 84, 66, 46, 73, 110, 116, 105, 97, 108, 69, 114, 114, 78, 98, 114, 68, 108, 46, 81, 112, 115, 107, 1, 32, 0, 0, 1, 96, 84, 66, 46, 73, 110, 116, 105, 97, 108, 69, 114, 114, 78, 98, 114, 68, 108, 46, 49, 54, 81, 97, 109, 1, 32, 0, 0, 1, 96, 84, 66, 46, 73, 110, 116, 105, 97, 108, 69, 114, 114, 78, 98, 114, 68, 108, 46, 54, 52, 81, 97, 109, 1, 32, 0, 0, 1, 112, 84, 66, 46, 73, 110, 116, 105, 97, 108, 69, 114, 114, 78, 98, 114, 68, 108, 46, 50, 53, 54, 81, 97, 109, 1, 32, 0, 0, 0, 192, 84, 66, 46, 84, 111, 116, 78, 98, 114, 68, 108, 46, 88, 1, 32, 0, 0, 1, 32, 84, 66, 46, 69, 114, 114, 84, 111, 108, 116, 97, 108, 78, 98, 114, 68, 108, 46, 88, 1, 32, 0, 0, 1, 32, 84, 66, 46, 82, 101, 115, 105, 100, 117, 97, 108, 69, 114, 114, 78, 98, 114, 68, 108, 1, 32, 0, 0, 0, 224, 84, 66, 46, 84, 111, 116, 78, 98, 114, 85, 108, 73, 110, 105, 116, 1, 32, 0, 0, 1, 48, 84, 66, 46, 84, 111, 116, 78, 98, 114, 85, 108, 73, 110, 105, 116, 46, 81, 112, 115, 107, 1, 32, 0, 0, 1, 64, 84, 66, 46, 84, 111, 116, 78, 98, 114, 85, 108, 73, 110, 105, 116, 46, 49, 54, 81, 97, 109, 1, 32, 0, 0, 1, 64, 84, 66, 46, 84, 111, 116, 78, 98, 114, 85, 108, 73, 110, 105, 116, 46, 54, 52, 81, 97, 109, 1, 32, 0, 0, 1, 80, 84, 66, 46, 84, 111, 116, 78, 98, 114, 85, 108, 73, 110, 105, 116, 46, 50, 53, 54, 81, 97, 109, 1, 32, 0, 0, 1, 16, 84, 66, 46, 69, 114, 114, 78, 98, 114, 85, 108, 73, 110, 105, 116, 105, 97, 108, 1, 32, 0, 0, 1, 96, 84, 66, 46, 69, 114, 114, 78, 98, 114, 85, 108, 73, 110, 105, 116, 105, 97, 108, 46, 81, 112, 115, 107, 1, 32, 0, 0, 1, 112, 84, 66, 46, 69, 114, 114, 78, 98, 114, 85, 108, 73, 110, 105, 116, 105, 97, 108, 46, 49, 54, 81, 97, 109, 1, 32, 0, 0, 1, 112, 84, 66, 46, 69, 114, 114, 78, 98, 114, 85, 108, 73, 110, 105, 116, 105, 97, 108, 46, 54, 52, 81, 97, 109, 1, 32, 0, 0, 1, 128, 84, 66, 46, 69, 114, 114, 78, 98, 114, 85, 108, 73, 110, 105, 116, 105, 97, 108, 46, 50, 53, 54, 81, 97, 109, 1, 32, 0, 0, 0, 192, 84, 66, 46, 84, 111, 116, 78, 98, 114, 85, 108, 46, 88, 1, 32, 0, 0, 1, 32, 84, 66, 46, 69, 114, 114, 84, 111, 108, 116, 97, 108, 78, 98, 114, 85, 108, 46, 88, 1, 32, 0, 0, 1, 32, 84, 66, 46, 82, 101, 115, 105, 100, 117, 97, 108, 69, 114, 114, 78, 98, 114, 85, 108, 1, 32, 0, 0, 0, 160, 86, 105, 97, 118, 105, 46, 71, 101, 111, 46, 120, 1, 32, 0, 0, 0, 160, 86, 105, 97, 118, 105, 46, 71, 101, 111, 46, 121, 1, 32, 0, 0, 0, 160, 86, 105, 97, 118, 105, 46, 71, 101, 111, 46, 122, 1, 32, 0, 0, 0, 0, 0, 0, 31, 1, 18, 52, 86, 0, 16}
	return
}

func ActionDefinitionFormat3EncodedByte() (ActionDefinitionFormat3 []int64) {
	//Support VIAVI RIC Test v1.5
	ActionDefinitionFormat3 = []int64{0, 1, 3, 72, 0, 62, 0, 160, 86, 105, 97, 118, 105, 46, 85, 69, 46, 105, 100, 0, 0, 16, 0, 0, 0, 96, 86, 105, 97, 118, 105, 46, 67, 101, 108, 108, 46, 105, 100, 0, 0, 16, 0, 0, 0, 104, 86, 105, 97, 118, 105, 46, 83, 108, 105, 99, 101, 46, 105, 100, 0, 0, 16, 0, 0, 0, 80, 68, 82, 66, 46, 85, 69, 84, 104, 112, 68, 108, 0, 0, 16, 0, 0, 0, 80, 68, 82, 66, 46, 85, 69, 84, 104, 112, 85, 108, 0, 0, 16, 0, 0, 0, 96, 82, 82, 85, 46, 80, 114, 98, 85, 115, 101, 100, 68, 108, 0, 0, 16, 0, 0, 0, 96, 82, 82, 85, 46, 80, 114, 98, 85, 115, 101, 100, 85, 108, 0, 0, 16, 0, 0, 0, 96, 82, 70, 46, 115, 101, 114, 118, 105, 110, 103, 46, 105, 100, 0, 0, 16, 0, 0, 0, 112, 82, 70, 46, 115, 101, 114, 118, 105, 110, 103, 46, 82, 83, 82, 80, 0, 0, 16, 0, 0, 0, 112, 82, 70, 46, 115, 101, 114, 118, 105, 110, 103, 46, 82, 83, 82, 81, 0, 0, 16, 0, 0, 0, 128, 82, 70, 46, 115, 101, 114, 118, 105, 110, 103, 46, 82, 83, 83, 73, 78, 82, 0, 0, 16, 0, 0, 0, 64, 82, 70, 46, 110, 98, 49, 46, 105, 100, 0, 0, 16, 0, 0, 0, 80, 82, 70, 46, 110, 98, 49, 46, 82, 83, 82, 80, 0, 0, 16, 0, 0, 0, 80, 82, 70, 46, 110, 98, 49, 46, 82, 83, 82, 81, 0, 0, 16, 0, 0, 0, 96, 82, 70, 46, 110, 98, 49, 46, 82, 83, 83, 73, 78, 82, 0, 0, 16, 0, 0, 0, 64, 82, 70, 46, 110, 98, 50, 46, 105, 100, 0, 0, 16, 0, 0, 0, 80, 82, 70, 46, 110, 98, 50, 46, 82, 83, 82, 80, 0, 0, 16, 0, 0, 0, 80, 82, 70, 46, 110, 98, 50, 46, 82, 83, 82, 81, 0, 0, 16, 0, 0, 0, 96, 82, 70, 46, 110, 98, 50, 46, 82, 83, 83, 73, 78, 82, 0, 0, 16, 0, 0, 0, 64, 82, 70, 46, 110, 98, 51, 46, 105, 100, 0, 0, 16, 0, 0, 0, 80, 82, 70, 46, 110, 98, 51, 46, 82, 83, 82, 80, 0, 0, 16, 0, 0, 0, 80, 82, 70, 46, 110, 98, 51, 46, 82, 83, 82, 81, 0, 0, 16, 0, 0, 0, 96, 82, 70, 46, 110, 98, 51, 46, 82, 83, 83, 73, 78, 82, 0, 0, 16, 0, 0, 0, 64, 82, 70, 46, 110, 98, 52, 46, 105, 100, 0, 0, 16, 0, 0, 0, 80, 82, 70, 46, 110, 98, 52, 46, 82, 83, 82, 80, 0, 0, 16, 0, 0, 0, 80, 82, 70, 46, 110, 98, 52, 46, 82, 83, 82, 81, 0, 0, 16, 0, 0, 0, 96, 82, 70, 46, 110, 98, 52, 46, 82, 83, 83, 73, 78, 82, 0, 0, 16, 0, 0, 0, 64, 82, 70, 46, 110, 98, 53, 46, 105, 100, 0, 0, 16, 0, 0, 0, 80, 82, 70, 46, 110, 98, 53, 46, 82, 83, 82, 80, 0, 0, 16, 0, 0, 0, 80, 82, 70, 46, 110, 98, 53, 46, 82, 83, 82, 81, 0, 0, 16, 0, 0, 0, 96, 82, 70, 46, 110, 98, 53, 46, 82, 83, 83, 73, 78, 82, 0, 0, 16, 0, 0, 0, 64, 82, 70, 46, 110, 98, 54, 46, 105, 100, 0, 0, 16, 0, 0, 0, 80, 82, 70, 46, 110, 98, 54, 46, 82, 83, 82, 80, 0, 0, 16, 0, 0, 0, 80, 82, 70, 46, 110, 98, 54, 46, 82, 83, 82, 81, 0, 0, 16, 0, 0, 0, 96, 82, 70, 46, 110, 98, 54, 46, 82, 83, 83, 73, 78, 82, 0, 0, 16, 0, 0, 0, 64, 82, 70, 46, 110, 98, 55, 46, 105, 100, 0, 0, 16, 0, 0, 0, 80, 82, 70, 46, 110, 98, 55, 46, 82, 83, 82, 80, 0, 0, 16, 0, 0, 0, 80, 82, 70, 46, 110, 98, 55, 46, 82, 83, 82, 81, 0, 0, 16, 0, 0, 0, 96, 82, 70, 46, 110, 98, 55, 46, 82, 83, 83, 73, 78, 82, 0, 0, 16, 0, 0, 0, 112, 84, 66, 46, 84, 111, 116, 78, 98, 114, 85, 108, 73, 110, 105, 116, 0, 0, 16, 0, 0, 0, 128, 84, 66, 46, 73, 110, 116, 105, 97, 108, 69, 114, 114, 78, 98, 114, 68, 108, 0, 0, 16, 0, 0, 0, 144, 84, 66, 46, 82, 101, 115, 105, 100, 117, 97, 108, 69, 114, 114, 78, 98, 114, 68, 108, 0, 0, 16, 0, 0, 0, 144, 84, 66, 46, 82, 101, 115, 105, 100, 117, 97, 108, 69, 114, 114, 78, 98, 114, 85, 108, 0, 0, 16, 0, 0, 0, 176, 84, 66, 46, 84, 111, 116, 78, 98, 114, 68, 108, 73, 110, 105, 116, 105, 97, 108, 46, 81, 112, 115, 107, 0, 0, 16, 0, 0, 0, 184, 84, 66, 46, 84, 111, 116, 78, 98, 114, 68, 108, 73, 110, 105, 116, 105, 97, 108, 46, 49, 54, 81, 97, 109, 0, 0, 16, 0, 0, 0, 184, 84, 66, 46, 84, 111, 116, 78, 98, 114, 68, 108, 73, 110, 105, 116, 105, 97, 108, 46, 54, 52, 81, 97, 109, 0, 0, 16, 0, 0, 0, 192, 84, 66, 46, 84, 111, 116, 78, 98, 114, 68, 108, 73, 110, 105, 116, 105, 97, 108, 46, 50, 53, 54, 81, 97, 109, 0, 0, 16, 0, 0, 0, 168, 84, 66, 46, 73, 110, 116, 105, 97, 108, 69, 114, 114, 78, 98, 114, 68, 108, 46, 81, 112, 115, 107, 0, 0, 16, 0, 0, 0, 176, 84, 66, 46, 73, 110, 116, 105, 97, 108, 69, 114, 114, 78, 98, 114, 68, 108, 46, 49, 54, 81, 97, 109, 0, 0, 16, 0, 0, 0, 176, 84, 66, 46, 73, 110, 116, 105, 97, 108, 69, 114, 114, 78, 98, 114, 68, 108, 46, 54, 52, 81, 97, 109, 0, 0, 16, 0, 0, 0, 184, 84, 66, 46, 73, 110, 116, 105, 97, 108, 69, 114, 114, 78, 98, 114, 68, 108, 46, 50, 53, 54, 81, 97, 109, 0, 0, 16, 0, 0, 0, 152, 84, 66, 46, 84, 111, 116, 78, 98, 114, 85, 108, 73, 110, 105, 116, 46, 81, 112, 115, 107, 0, 0, 16, 0, 0, 0, 160, 84, 66, 46, 84, 111, 116, 78, 98, 114, 85, 108, 73, 110, 105, 116, 46, 49, 54, 81, 97, 109, 0, 0, 16, 0, 0, 0, 160, 84, 66, 46, 84, 111, 116, 78, 98, 114, 85, 108, 73, 110, 105, 116, 46, 54, 52, 81, 97, 109, 0, 0, 16, 0, 0, 0, 168, 84, 66, 46, 84, 111, 116, 78, 98, 114, 85, 108, 73, 110, 105, 116, 46, 50, 53, 54, 81, 97, 109, 0, 0, 16, 0, 0, 0, 136, 84, 66, 46, 69, 114, 114, 78, 98, 114, 85, 108, 73, 110, 105, 116, 105, 97, 108, 0, 0, 16, 0, 0, 0, 176, 84, 66, 46, 69, 114, 114, 78, 98, 114, 85, 108, 73, 110, 105, 116, 105, 97, 108, 46, 81, 112, 115, 107, 0, 0, 16, 0, 0, 0, 184, 84, 66, 46, 69, 114, 114, 78, 98, 114, 85, 108, 73, 110, 105, 116, 105, 97, 108, 46, 49, 54, 81, 97, 109, 0, 0, 16, 0, 0, 0, 184, 84, 66, 46, 69, 114, 114, 78, 98, 114, 85, 108, 73, 110, 105, 116, 105, 97, 108, 46, 54, 52, 81, 97, 109, 0, 0, 16, 0, 0, 0, 192, 84, 66, 46, 69, 114, 114, 78, 98, 114, 85, 108, 73, 110, 105, 116, 105, 97, 108, 46, 50, 53, 54, 81, 97, 109, 0, 0, 16, 0, 0, 0, 80, 86, 105, 97, 118, 105, 46, 71, 101, 111, 46, 120, 0, 0, 16, 0, 0, 0, 80, 86, 105, 97, 118, 105, 46, 71, 101, 111, 46, 121, 0, 0, 16, 0, 0, 0, 80, 86, 105, 97, 118, 105, 46, 71, 101, 111, 46, 122, 0, 0, 16, 0, 0, 0, 0, 0, 0, 31, 1, 18, 52, 92, 0, 16}
	return
}

func GenerateActionDefinition(RanName string, ReportStyleItem RIC_ReportStyle_Item) (ActionToBeSetupItem apimodel.ActionToBeSetup, err error) {
	ActionFormatType := ReportStyleItem.ric_ActionFormat_Type
	ActionDefinition := []int64{} //[]byte{}

	switch ActionFormatType {
	case 1:
		ActionDefinition = ActionDefinitionFormat1EncodedByte()
		//ActionDefinition, err = GenerateActionDefinitionFormat1(RanName, ReportStyleItem)
	case 2:
		return ActionToBeSetupItem, errors.New("kpm doesn't support action type 2")
	case 3:
		return ActionToBeSetupItem, errors.New("kpm doesn't support action type 3")
		//ActionDefinition, err = GenerateActionDefinitionFormat3(RanName, ReportStyleItem)
	case 4:
		return ActionToBeSetupItem, errors.New("kpm doesn't support action type 4")
	case 5:
		return ActionToBeSetupItem, errors.New("kpm doesn't support action type 5")
	default:
		return ActionToBeSetupItem, errors.New("kpm doesn't support default action type")
	}

	if err != nil {
		return ActionToBeSetupItem, err
	}

	ActionToBeSetupItem = apimodel.ActionToBeSetup{
		ActionDefinition: ActionDefinition, //ByteSlice2Int64Slice(ActionDefinition),
		ActionID:         &ActionFormatType,
		ActionType:       &ActionTypeReport,
		SubsequentAction: nil,
	}
	return ActionToBeSetupItem, nil
}

func GenerateActionToBeSetupList(RanName string, ReportStyleList []RIC_ReportStyle_Item) (ActionToBeSetupList []*apimodel.ActionToBeSetup, err error) {
	//Currently, kpm only supports styletype = 1
	ActionToBeSetupList = []*apimodel.ActionToBeSetup{}
	for i := 0; i < len(ReportStyleList); i++ {
		ActionToBeSetupItem, err := GenerateActionDefinition(RanName, ReportStyleList[i])
		if err != nil {
			xapp.Logger.Error("Failed to generate ActionDefinition, err = %v", err)
			//fmt.Println(fmt.Sprintf("Failed to generate ActionDefinition, err = %v", err))
		} else {
			ActionToBeSetupList = append(ActionToBeSetupList, &ActionToBeSetupItem)
		}
	}

	if len(ActionToBeSetupList) == 0 {
		return ActionToBeSetupList, errors.New("kpm doesn't support all the action types")
	} else {
		return ActionToBeSetupList, nil
	}
}

func GenerateSubscriptionDetail(RanName string, RanFunDef *E2SM_KPM_RANfunction_Description) (SubscriptionDetails apimodel.SubscriptionDetailsList, err error) {
	EventTriggerDefinition, err := GenerateEventTriggerDefinition()
	if err != nil {
		xapp.Logger.Error("Failed to generate EventTriggerDefinition, err = %v", err)
		//fmt.Println(fmt.Sprintf("Failed to generate EventTriggerDefinition, err = %v", err))
		return make(apimodel.SubscriptionDetailsList, 0), err
	}

	ActionToBeSetupList, err := GenerateActionToBeSetupList(RanName, RanFunDef.ric_ReportStyle_List)
	if err != nil {
		xapp.Logger.Error("Failed to generate ActionToBeSetupList, err = %v", err)
		//fmt.Println(fmt.Sprintf("Failed to generate ActionToBeSetupList, err = %v", err))
		return make(apimodel.SubscriptionDetailsList, 0), err
	}

	xappEventInstanceID := XappEventInstanceID
	XappEventInstanceID++

	SubscriptionDetails = []*apimodel.SubscriptionDetail{}
	SubscriptionDetail := apimodel.SubscriptionDetail{
		ActionToBeSetupList: ActionToBeSetupList,
		EventTriggers:       EventTriggerDefinition,
		XappEventInstanceID: &xappEventInstanceID,
	}

	SubscriptionDetails = append(SubscriptionDetails, &SubscriptionDetail)
	return SubscriptionDetails, nil
}

func GenerateSubscriptionRequestPayload(RanName string, RanFunId int64, RanFunDef *E2SM_KPM_RANfunction_Description) (SubscriptionRerquestParams *apimodel.SubscriptionParams, err error) {
	SubscriptionDetails, err := GenerateSubscriptionDetail(RanName, RanFunDef)
	if err != nil {
		xapp.Logger.Error("Failed to generate subscription detail")
		return nil, err
	}

	SubscriptionRerquestParams = &apimodel.SubscriptionParams{
		ClientEndpoint:           GetClientEndPoint(),
		E2SubscriptionDirectives: nil,
		Meid:                     &RanName,
		RANFunctionID:            &RanFunId,
		SubscriptionDetails:      SubscriptionDetails,
		SubscriptionID:           "",
	}
	return SubscriptionRerquestParams, nil
}

func SubscriptionResponseCallback(SubscriptionResponse *apimodel.SubscriptionResponse) {
	xapp.Logger.Debug("Received SubscriptionResponseCallback")
	if SubscriptionResponse == nil {
		xapp.Logger.Error("nil SubscriptionResponse")
		return
	}

	xapp.Logger.Debug("Received Subscription Id = %s, %d Subscription Instances in Total", *SubscriptionResponse.SubscriptionID, len(SubscriptionResponse.SubscriptionInstances))

	for i := 0; i < len(SubscriptionResponse.SubscriptionInstances); i++ {
		SubIns := SubscriptionResponse.SubscriptionInstances[i]
		// Due to ErrorCause of submgr is different to the definition. Here, I just add another check.
		if SubIns.ErrorCause != "" && SubIns.ErrorCause != " " {
			xapp.Logger.Error("Subscription[%d]: Error Source: %s, Timeout Type: %s", i, SubIns.ErrorSource, SubIns.TimeoutType)

			//Unsubscribe Subscription
			if SubscriptionResponse.SubscriptionID != nil {
				xapp.Subscription.Unsubscribe(*SubscriptionResponse.SubscriptionID)
			}

			return

		} else {
			xapp.Logger.Debug("Subscription[%d]: E2EventInstanceID = %d, XappEventInstanceID = %d", i, SubIns.E2EventInstanceID, SubIns.XappEventInstanceID)

			//Todo: Verify Subscription

		}

	}

}
