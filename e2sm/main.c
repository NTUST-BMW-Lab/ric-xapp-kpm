#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <asn_application.h>
#include "constr_TYPE.h"
#include "E2SM-KPM-ActionDefinition-Format1.h"
#include "E2SM-KPM-IndicationHeader-Format1.h"
#include "wrapper.h"
#include "RANUEID.h"
#include "UEID-GNB-DU.h"

//void VerifyRANFunctionDefinitionDecoding();
//void VerifyEventTriggerDefinitionEncoding();
//void VerifyActionDefinitionEncoding();
void VerifyIndicationHeaderDecoding();
void VerifyIndicationHeaderEncoding();

int ASN_Print_Flag = 1;

int main(){
    VerifyIndicationHeaderDecoding();
    //VerifyIndicationHeaderEncoding();
    //VerifyActionDefinitionEncoding();
    return 0;
}

// gcc -I/usr/local/include/e2sm main.c -le2smwrapper -lm -o main

uint8_t ConvertByte2Int(char c){
    if (c >= 'A'){
        //printf("%d\n",(c - 'A' + 10));
        return (c - 'A' + 10) ;
    }else if(c >= '0'){
        //printf("%d\n",(c - '0'));
        return (c - '0') ;
    }
    return 0;
}
/*
void VerifyRANFunctionDefinitionDecoding(){
    char Buffer[7429] = "68304F52414E2D4532534D2D4B504D000018312E332E362E312E342E312E35333134382E312E322E322E3208804B504D204D6F6E69746F72207630322E303001020001010700506572696F646963205265706F7274010108010109004532204E6F6465204D6561737572656D656E740101002A40A04E522D43474900000040A04E522D5043490000014100474E422D44552D494400000241404452422E5545546870446C00000341404452422E5545546870556C00000442C0516F73466C6F772E50646370506475566F6C756D65556C00000542C0516F73466C6F772E50646370506475566F6C756D65446C00000641605252432E436F6E6E4D65616E00000741405252432E436F6E6E4D617800000842605252432E496E616374697665436F6E6E4D65616E00000942405252432E496E616374697665436F6E6E4D617800000A41A05252552E507262417661696C446C00000B41A05252552E507262417661696C556C00000C41805252552E50726255736564446C00000D41805252552E50726255736564556C00000E42C054422E546F744E6272446C496E697469616C2E5170736B00000F42E054422E546F744E6272446C496E697469616C2E313651616D00001042E054422E546F744E6272446C496E697469616C2E363451616D000011430054422E546F744E6272446C496E697469616C2E32353651616D000012420054422E496E7469616C4572724E6272446C00001342A054422E496E7469616C4572724E6272446C2E5170736B00001442C054422E496E7469616C4572724E6272446C2E313651616D00001542C054422E496E7469616C4572724E6272446C2E363451616D00001642E054422E496E7469616C4572724E6272446C2E32353651616D000017418054422E546F744E6272446C2E58000018424054422E457272546F6C74616C4E6272446C2E58000019424054422E526573696475616C4572724E6272446C00001A41C054422E546F744E6272556C496E697400001B426054422E546F744E6272556C496E69742E5170736B00001C428054422E546F744E6272556C496E69742E313651616D00001D428054422E546F744E6272556C496E69742E363451616D00001E42A054422E546F744E6272556C496E69742E32353651616D00001F422054422E4572724E6272556C496E697469616C00002042C054422E4572724E6272556C496E697469616C2E5170736B00002142E054422E4572724E6272556C496E697469616C2E313651616D00002242E054422E4572724E6272556C496E697469616C2E363451616D000023430054422E4572724E6272556C496E697469616C2E32353651616D000024418054422E546F744E6272556C2E58000025424054422E457272546F6C74616C4E6272556C2E58000026424054422E526573696475616C4572724E6272556C000027414056696176692E47656F2E78000028414056696176692E47656F2E79000029414056696176692E47656F2E7A00002A0101010100010211004532204E6F6465204D6561737572656D656E7420666F7220612073696E676C652055450102003E414056696176692E55452E696400002B418056696176692E43656C6C2E696400002C41A056696176692E536C6963652E696400002D41404452422E5545546870446C00000341404452422E5545546870556C00000441805252552E50726255736564446C00000D41805252552E50726255736564556C00000E418052462E73657276696E672E696400002E41C052462E73657276696E672E5253525000002F41C052462E73657276696E672E52535251000030420052462E73657276696E672E525353494E52000031410052462E6E62312E6964000032414052462E6E62312E52535250000033414052462E6E62312E52535251000034418052462E6E62312E525353494E52000035410052462E6E62322E6964000036414052462E6E62322E52535250000037414052462E6E62322E52535251000038418052462E6E62322E525353494E52000039410052462E6E62332E696400003A414052462E6E62332E5253525000003B414052462E6E62332E5253525100003C418052462E6E62332E525353494E5200003D410052462E6E62342E696400003E414052462E6E62342E5253525000003F414052462E6E62342E52535251000040418052462E6E62342E525353494E52000041410052462E6E62352E6964000042414052462E6E62352E52535250000043414052462E6E62352E52535251000044418052462E6E62352E525353494E52000045410052462E6E62362E6964000046414052462E6E62362E52535250000047414052462E6E62362E52535251000048418052462E6E62362E525353494E52000049410052462E6E62372E696400004A414052462E6E62372E5253525000004B414052462E6E62372E5253525100004C418052462E6E62372E525353494E5200004D41C054422E546F744E6272556C496E697400001B420054422E496E7469616C4572724E6272446C000013424054422E526573696475616C4572724E6272446C00001A424054422E526573696475616C4572724E6272556C00002742C054422E546F744E6272446C496E697469616C2E5170736B00000F42E054422E546F744E6272446C496E697469616C2E313651616D00001042E054422E546F744E6272446C496E697469616C2E363451616D000011430054422E546F744E6272446C496E697469616C2E32353651616D00001242A054422E496E7469616C4572724E6272446C2E5170736B00001442C054422E496E7469616C4572724E6272446C2E313651616D00001542C054422E496E7469616C4572724E6272446C2E363451616D00001642E054422E496E7469616C4572724E6272446C2E32353651616D000017426054422E546F744E6272556C496E69742E5170736B00001C428054422E546F744E6272556C496E69742E313651616D00001D428054422E546F744E6272556C496E69742E363451616D00001E42A054422E546F744E6272556C496E69742E32353651616D00001F422054422E4572724E6272556C496E697469616C00002042C054422E4572724E6272556C496E697469616C2E5170736B00002142E054422E4572724E6272556C496E697469616C2E313651616D00002242E054422E4572724E6272556C496E697469616C2E363451616D000023430054422E4572724E6272556C496E697469616C2E32353651616D000024414056696176692E47656F2E78000028414056696176692E47656F2E79000029414056696176692E47656F2E7A00002A010101010001031600436F6E646974696F6E2D62617365642C2055452D6C6576656C204532204E6F6465204D6561737572656D656E740103003E414056696176692E55452E696400002B418056696176692E43656C6C2E696400002C41A056696176692E536C6963652E696400002D41404452422E5545546870446C00000341404452422E5545546870556C00000441805252552E50726255736564446C00000D41805252552E50726255736564556C00000E418052462E73657276696E672E696400002E41C052462E73657276696E672E5253525000002F41C052462E73657276696E672E52535251000030420052462E73657276696E672E525353494E52000031410052462E6E62312E6964000032414052462E6E62312E52535250000033414052462E6E62312E52535251000034418052462E6E62312E525353494E52000035410052462E6E62322E6964000036414052462E6E62322E52535250000037414052462E6E62322E52535251000038418052462E6E62322E525353494E52000039410052462E6E62332E696400003A414052462E6E62332E5253525000003B414052462E6E62332E5253525100003C418052462E6E62332E525353494E5200003D410052462E6E62342E696400003E414052462E6E62342E5253525000003F414052462E6E62342E52535251000040418052462E6E62342E525353494E52000041410052462E6E62352E6964000042414052462E6E62352E52535250000043414052462E6E62352E52535251000044418052462E6E62352E525353494E52000045410052462E6E62362E6964000046414052462E6E62362E52535250000047414052462E6E62362E52535251000048418052462E6E62362E525353494E52000049410052462E6E62372E696400004A414052462E6E62372E5253525000004B414052462E6E62372E5253525100004C418052462E6E62372E525353494E5200004D41C054422E546F744E6272556C496E697400001B420054422E496E7469616C4572724E6272446C000013424054422E526573696475616C4572724E6272446C00001A424054422E526573696475616C4572724E6272556C00002742C054422E546F744E6272446C496E697469616C2E5170736B00000F42E054422E546F744E6272446C496E697469616C2E313651616D00001042E054422E546F744E6272446C496E697469616C2E363451616D000011430054422E546F744E6272446C496E697469616C2E32353651616D00001242A054422E496E7469616C4572724E6272446C2E5170736B00001442C054422E496E7469616C4572724E6272446C2E313651616D00001542C054422E496E7469616C4572724E6272446C2E363451616D00001642E054422E496E7469616C4572724E6272446C2E32353651616D000017426054422E546F744E6272556C496E69742E5170736B00001C428054422E546F744E6272556C496E69742E313651616D00001D428054422E546F744E6272556C496E69742E363451616D00001E42A054422E546F744E6272556C496E69742E32353651616D00001F422054422E4572724E6272556C496E697469616C00002042C054422E4572724E6272556C496E697469616C2E5170736B00002142E054422E4572724E6272556C496E697469616C2E313651616D00002242E054422E4572724E6272556C496E697469616C2E363451616D000023430054422E4572724E6272556C496E697469616C2E32353651616D000024414056696176692E47656F2E78000028414056696176692E47656F2E79000029414056696176692E47656F2E7A00002A01010102\0";
    uint8_t RanFunctionDefinitionByte[(7429-1)/2] ;
    for (int i = 0; i< 7428; i=i+2){
        RanFunctionDefinitionByte[i/2] = ConvertByte2Int(Buffer[i])*16 +  ConvertByte2Int(Buffer[i+1]) ;
        //printf("%d ", RanFunctionDefinitionByte[i/2]) ;
    }
    E2SM_KPM_RANfunction_Description_t *RanFunctionDefinition = 0;
    RanFunctionDefinition = Decode_RAN_Function_Description((void *)RanFunctionDefinitionByte, sizeof(RanFunctionDefinitionByte),1);
    Free_RAN_Function_Dscription(RanFunctionDefinition);
}
*/
/*
void VerifyEventTriggerDefinitionEncoding(){
    uint8_t Buffer[1500];
    size_t Buf_Size = 1500;
    ssize_t Coded_Size;
    long Report_Period = 1;

    Coded_Size = Encode_Event_Trigger_Definition((void *)Buffer, Buf_Size, Report_Period, ASN_Print_Flag);
    if(Coded_Size == -1){
        fprintf(stderr, "Failed to encode event trigger definition\n") ;
        exit(1);
    }else{
        fprintf(stderr, "After encoding EventTrigger Definition, Code Length = %ld\n", Coded_Size) ;
    }
    
    fprintf(stderr, "\n\nTest Decode EventTriggerDefinition\n\n") ;

    uint8_t *ReceiveBuffer = (uint8_t*)malloc(Coded_Size * sizeof(uint8_t) ) ;
    memcpy(ReceiveBuffer, Buffer, Coded_Size) ;

    printf("\n");
    
    asn_dec_rval_t Result;
    E2SM_KPM_EventTriggerDefinition_t *EventTrigger_Decode = 0;
    Result = aper_decode_complete(NULL, &asn_DEF_E2SM_KPM_EventTriggerDefinition, (void **)&EventTrigger_Decode, ReceiveBuffer, Coded_Size);
    if(Result.code == RC_OK){
        fprintf(stderr, "Success\n") ;
        asn_fprint(stderr,  &asn_DEF_E2SM_KPM_EventTriggerDefinition, EventTrigger_Decode);
    }else{
        fprintf(stderr, "Fail\n") ;
        ASN_STRUCT_FREE(asn_DEF_E2SM_KPM_EventTriggerDefinition, EventTrigger_Decode); 
        exit(1) ;
    } 

}
*/
/*
void VerifyActionDefinitionEncoding(){
    printf("%d\n",ilogb(10.0)) ;
    
    MeasurementTypeID_t MeaId;
    MeaId = 1;

    LabelInfoItem_t *LabInfoItem = malloc(sizeof(LabelInfoItem_t));

    MeasurementLabel_t measLabel;
    long int avg = MeasurementLabel__avg_true;
    measLabel.avg = &avg;
    measLabel.noLabel = NULL;
    measLabel.aRPmax = NULL;
    measLabel.aRPmin = NULL;
    measLabel.bitrateRange = NULL;
    measLabel.distBinX = NULL;
    measLabel.distBinY = NULL;
    measLabel.distBinZ = NULL;
    measLabel.fiveQI = NULL;
    measLabel.layerMU_MIMO = NULL;
    measLabel.max = NULL;
    measLabel.min = NULL;
    measLabel.plmnID = NULL;
    measLabel.preLabelOverride = NULL;
    measLabel.qCI = NULL;
    measLabel.qCImax = NULL;
    measLabel.qCImin = NULL;
    measLabel.qFI = NULL;
    measLabel.sliceID = NULL;
    measLabel.startEndInd = NULL;
    measLabel.sUM = NULL;
    
    LabInfoItem->measLabel = measLabel;

    //Test Pack_Measurement_Information Function 
    fprintf(stderr, "\n\nTest Pack_Measurement_Information Function\n\n") ;
    MeasurementInfoItem_t *MeaInfor2 = (MeasurementInfoItem_t*)malloc(sizeof(MeasurementInfoItem_t));
    assert(MeaInfor2 != 0);
    MeaInfor2 = Pack_Measurement_Information(NULL, &MeaId, &LabInfoItem, 1);
    asn_fprint(stderr,  &asn_DEF_MeasurementInfoItem, MeaInfor2); 

    //Test Pack_Measurement_Information_List Function 
    fprintf(stderr, "\n\nTest Pack_Measurement_Information_List Function\n\n") ;
    MeasurementInfoList_t *MeaInforList = (MeasurementInfoList_t*)malloc(sizeof(MeasurementInfoList_t));
    assert(MeaInforList != 0);
    MeaInforList = Pack_Measurement_Information_List(&MeaInfor2, 1);
    asn_fprint(stderr,  &asn_DEF_MeasurementInfoList, MeaInforList);

    //Test Pack_ActionDefinition_Format1 Function 
    fprintf(stderr, "\n\nTest Pack_ActionDefinition_Format1 Function\n\n") ;
    E2SM_KPM_ActionDefinition_Format1_t *ActionFormat1 = (E2SM_KPM_ActionDefinition_Format1_t*)malloc(sizeof(E2SM_KPM_ActionDefinition_Format1_t));
    assert(ActionFormat1 != 0);

    ActionFormat1 = Pack_ActionDefinition_Format1(MeaInforList, 10, NULL);
    asn_fprint(stderr,  &asn_DEF_E2SM_KPM_ActionDefinition_Format1, ActionFormat1);

    //Test Encode_Action_Definition_Format1 Function 
    fprintf(stderr, "\n\nTest Encode_Action_Definition_Format1 Function\n\n") ;
    uint8_t Buffer[1500];
    size_t Buf_Size = 1500;
    ssize_t Coded_Size;
    Coded_Size = Encode_Action_Definition_Format1(Buffer, Buf_Size, ActionFormat1, ASN_Print_Flag);
    if(Coded_Size == -1){
        fprintf(stderr, "Failed to encode Action Format 1\n") ;
        exit(1);
    }else{
        fprintf(stderr, "After encoding Action Format 1, Code Length = %ld\n", Coded_Size) ;
    }

    //Test Decode_Action_Definition_Format1_Byte Function 
    fprintf(stderr, "\n\nTest Decode_Action_Definition_Format1_Byte Function\n\n") ;

    uint8_t *ReceiveBuffer = (uint8_t*)malloc(Coded_Size * sizeof(uint8_t) ) ;
    memcpy(ReceiveBuffer, Buffer, Coded_Size) ;

    asn_dec_rval_t Result;
    E2SM_KPM_ActionDefinition_t *ActionFormat1_Decode = 0;
    Result = aper_decode_complete(NULL, &asn_DEF_E2SM_KPM_ActionDefinition, (void **)&ActionFormat1_Decode, ReceiveBuffer, Coded_Size);
    if(Result.code == RC_OK){
        fprintf(stderr, "Success\n") ;
        asn_fprint(stderr,  &asn_DEF_E2SM_KPM_ActionDefinition, ActionFormat1_Decode);
    }else{
        fprintf(stderr, "Fail\n") ;
        ASN_STRUCT_FREE(asn_DEF_E2SM_KPM_ActionDefinition, ActionFormat1_Decode);
        exit(1) ;
    } 

    //Test Encode_Action_Definition_Format1 Function 
    UEID_t UEID;
    UEID.present = UEID_PR_gNB_DU_UEID;

    //UEID.choice.gNB_UEID->amf_UE_NGAP_ID = NGAP_Id_;
    UEID_GNB_DU_t *GNB_DU = (UEID_GNB_DU_t *)malloc(sizeof(UEID_GNB_DU_t));
    GNB_DU->gNB_CU_UE_F1AP_ID = 10000;

    uint8_t RAN_UEID[] = "1234567"; //size = 8
    size_t RAN_UEID_Size = sizeof(RAN_UEID);

    RANUEID_t *ran_UEID = (RANUEID_t *)malloc(sizeof(RANUEID_t));
    ran_UEID->buf = RAN_UEID;
    ran_UEID->size = RAN_UEID_Size;
    GNB_DU->ran_UEID = ran_UEID;

    UEID.choice.gNB_DU_UEID = GNB_DU;

    fprintf(stderr, "\n\nTest Encode_Action_Definition_Format2 Function\n\n") ;
    uint8_t Buffer2[1500];
    size_t Buf_Size2 = 1500;
    ssize_t Coded_Size2;
    Coded_Size2 = Encode_Action_Definition_Format2(Buffer2, Buf_Size2, UEID, ActionFormat1, ASN_Print_Flag);
    if(Coded_Size2 == -1){
        fprintf(stderr, "Failed to encode Action Format 2\n") ;
        exit(1);
    }else{
        fprintf(stderr, "After encoding Action Format 2, Code Length = %ld\n", Coded_Size2) ;
    }

    //Test Decode_Action_Definition_Format2_Byte Function 
    fprintf(stderr, "\n\nTest Decode_Action_Definition_Format2_Byte Function\n\n") ;

    uint8_t *ReceiveBuffer2 = (uint8_t*)malloc(Coded_Size2 * sizeof(uint8_t) ) ;
    memcpy(ReceiveBuffer2, Buffer2, Coded_Size2) ;

    asn_dec_rval_t Result2;
    E2SM_KPM_ActionDefinition_t *ActionFormat2_Decode = 0;
    Result2 = aper_decode_complete(NULL, &asn_DEF_E2SM_KPM_ActionDefinition, (void **)&ActionFormat2_Decode, ReceiveBuffer2, Coded_Size2);
    if(Result2.code == RC_OK){
        fprintf(stderr, "Success\n") ;
        asn_fprint(stderr,  &asn_DEF_E2SM_KPM_ActionDefinition, ActionFormat2_Decode);
    }else{
        fprintf(stderr, "Fail\n") ;
        ASN_STRUCT_FREE(asn_DEF_E2SM_KPM_ActionDefinition, ActionFormat2_Decode);
        exit(1) ;
    } 
    
    //Test Encode_Action_Definition_Format3 Function 
    MatchingCondList_t *CondList = 0;
    MatchingCondItem_t *CondItem = (MatchingCondItem_t *)malloc(sizeof(MatchingCondItem_t));
    CondItem->choice.measLabel = &measLabel;
    CondItem->present = MatchingCondItem_PR_measLabel;
    
    CondList = Pack_Matching_Condition_List(&measLabel, NULL, 1, 0);
    
    MeasurementCondItem_t *MeaCondItem = (MeasurementCondItem_t *)malloc(sizeof(MeasurementCondItem_t));
    MeaCondItem = Pack_Measurement_Condition_Item(NULL, &MeaId, CondList);

    MeasurementCondList_t *MeaCondList = (MeasurementCondList_t *)malloc(sizeof(MeasurementCondList_t));
    MeaCondList = Pack_Measurement_Condition_List(MeaCondItem, 1);

    fprintf(stderr, "\n\nTest Encode_Action_Definition_Format3 Function\n\n") ;
    uint8_t Buffer3[1500];
    size_t Buf_Size3 = 1500;
    ssize_t Coded_Size3;
    Coded_Size3 = Encode_Action_Definition_Format3(Buffer3, Buf_Size3, MeaCondList, 10, NULL, ASN_Print_Flag);
    if(Coded_Size3 == -1){
        fprintf(stderr, "Failed to encode Action Format 3\n") ;
        exit(1);
    }else{
        fprintf(stderr, "After encoding Action Format 3, Code Length = %ld\n", Coded_Size3) ;
    }

    //Test Decode_Action_Definition_Format2_Byte Function 
    fprintf(stderr, "\n\nTest Decode_Action_Definition_Format3_Byte Function\n\n") ;

    uint8_t *ReceiveBuffer3 = (uint8_t*)malloc(Coded_Size3 * sizeof(uint8_t) ) ;
    memcpy(ReceiveBuffer3, Buffer3, Coded_Size3) ;

    asn_dec_rval_t Result3;
    E2SM_KPM_ActionDefinition_t *ActionFormat3_Decode = 0;
    Result3 = aper_decode_complete(NULL, &asn_DEF_E2SM_KPM_ActionDefinition, (void **)&ActionFormat3_Decode, ReceiveBuffer3, Coded_Size3);
    if(Result3.code == RC_OK){
        fprintf(stderr, "Success\n") ;
        asn_fprint(stderr,  &asn_DEF_E2SM_KPM_ActionDefinition, ActionFormat3_Decode);
    }else{
        fprintf(stderr, "Fail\n") ;
        ASN_STRUCT_FREE(asn_DEF_E2SM_KPM_ActionDefinition, ActionFormat3_Decode);
        exit(1) ;
    } 
}
*/

void VerifyIndicationHeaderDecoding(){
    uint8_t Payload[] = {14, 231, 27, 163, 51, 0, 0, 6, 68, 85, 32, 49, 58, 49, 16, 68, 85, 28, 86, 105, 97, 118, 105, 32, 82, 73, 67, 32, 84, 101, 115, 116} ;
    
    E2SM_KPM_IndicationHeader_t *IndicationHeader = 0;
    IndicationHeader = Decode_Indication_Header(Payload, sizeof(Payload), ASN_Print_Flag);

    if(IndicationHeader == NULL){
        fprintf(stderr, "Failed to decode E2SM-KPM IndicationHeader\n");
    }
}

void VerifyIndicationHeaderEncoding(){
    uint8_t time[] = {231, 27, 162, 171};
    TimeStamp_t	 colletStartTime;
    colletStartTime.buf = time;
    colletStartTime.size = 4;

    uint8_t SenderName[] = {"DU 1:1"};
    PrintableString_t senderName;
    senderName.buf = SenderName;
    senderName.size = 7;

    uint8_t SenderType[] = {"DU"};
    PrintableString_t senderType;
    senderType.buf = SenderType;
    senderType.size = 3;

    uint8_t VendorName[] = {"Viavi RIC Test"};
    PrintableString_t vendorName;
    vendorName.buf = VendorName;
    vendorName.size = 15;

    E2SM_KPM_IndicationHeader_Format1_t* IndicationHeader_Format1 = (E2SM_KPM_IndicationHeader_Format1_t*)malloc(sizeof(E2SM_KPM_IndicationHeader_Format1_t));

    IndicationHeader_Format1->colletStartTime = colletStartTime;
    IndicationHeader_Format1->senderName = &senderName;
    IndicationHeader_Format1->senderType = &senderType;
    IndicationHeader_Format1->vendorName = &vendorName;

    E2SM_KPM_IndicationHeader_t* IndicationHeader = (E2SM_KPM_IndicationHeader_t*)malloc(sizeof(E2SM_KPM_IndicationHeader_t)) ;
    IndicationHeader->indicationHeader_formats.present = E2SM_KPM_IndicationHeader__indicationHeader_formats_PR_indicationHeader_Format1;
    IndicationHeader->indicationHeader_formats.choice.indicationHeader_Format1 = IndicationHeader_Format1;

    uint8_t Buffer[1500];
    size_t Buf_Size = 1500;
    ssize_t Coded_Size;

    Coded_Size = Encode_Indication_Header(Buffer, Buf_Size, IndicationHeader, ASN_Print_Flag) ;

    if(Coded_Size < 0){
        fprintf(stderr, "Failed to Encode E2SM-KPM IndicationHeader\n");
    }else{
        asn_fprint(stderr,  &asn_DEF_E2SM_KPM_IndicationHeader, IndicationHeader);
        printf("After encoding, length of bit = %ld\n",Coded_Size);
        
         //Due to unit of length is bit => We need to divide by 8 into byte
        for(int i =0; i<Coded_Size/8;i++){
            printf("%d ",Buffer[i]);
        }
    }
    //After encoding, Total 280 bits. 280/8 = 35bytes.
    uint8_t* Payload = (uint8_t*)malloc((Coded_Size)*sizeof(uint8_t));

    printf("sizeof Payload = %ld\n", sizeof(Payload));
    memcpy(Payload, Buffer, Coded_Size) ;

    E2SM_KPM_IndicationHeader_t *IndicationHeader_2 = 0;
    IndicationHeader_2 = Decode_Indication_Header(Payload, Coded_Size, ASN_Print_Flag);

    if(IndicationHeader_2 == NULL){
        fprintf(stderr, "Failed to decode E2SM-KPM IndicationHeader\n");
    }
}