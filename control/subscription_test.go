package control

import (
	"fmt"
	"testing"
)

func TestGenerateSubscriptionRequestPayload(t *testing.T) {
	s := string("68304F52414E2D4532534D2D4B504D000018312E332E362E312E342E312E35333134382E312E322E322E3208804B504D204D6F6E69746F72207630322E303001020001010700506572696F646963205265706F7274010108010109004532204E6F6465204D6561737572656D656E740101002A40A04E522D43474900000040A04E522D5043490000014100474E422D44552D494400000241404452422E5545546870446C00000341404452422E5545546870556C00000442C0516F73466C6F772E50646370506475566F6C756D65556C00000542C0516F73466C6F772E50646370506475566F6C756D65446C00000641605252432E436F6E6E4D65616E00000741405252432E436F6E6E4D617800000842605252432E496E616374697665436F6E6E4D65616E00000942405252432E496E616374697665436F6E6E4D617800000A41A05252552E507262417661696C446C00000B41A05252552E507262417661696C556C00000C41805252552E50726255736564446C00000D41805252552E50726255736564556C00000E42C054422E546F744E6272446C496E697469616C2E5170736B00000F42E054422E546F744E6272446C496E697469616C2E313651616D00001042E054422E546F744E6272446C496E697469616C2E363451616D000011430054422E546F744E6272446C496E697469616C2E32353651616D000012420054422E496E7469616C4572724E6272446C00001342A054422E496E7469616C4572724E6272446C2E5170736B00001442C054422E496E7469616C4572724E6272446C2E313651616D00001542C054422E496E7469616C4572724E6272446C2E363451616D00001642E054422E496E7469616C4572724E6272446C2E32353651616D000017418054422E546F744E6272446C2E58000018424054422E457272546F6C74616C4E6272446C2E58000019424054422E526573696475616C4572724E6272446C00001A41C054422E546F744E6272556C496E697400001B426054422E546F744E6272556C496E69742E5170736B00001C428054422E546F744E6272556C496E69742E313651616D00001D428054422E546F744E6272556C496E69742E363451616D00001E42A054422E546F744E6272556C496E69742E32353651616D00001F422054422E4572724E6272556C496E697469616C00002042C054422E4572724E6272556C496E697469616C2E5170736B00002142E054422E4572724E6272556C496E697469616C2E313651616D00002242E054422E4572724E6272556C496E697469616C2E363451616D000023430054422E4572724E6272556C496E697469616C2E32353651616D000024418054422E546F744E6272556C2E58000025424054422E457272546F6C74616C4E6272556C2E58000026424054422E526573696475616C4572724E6272556C000027414056696176692E47656F2E78000028414056696176692E47656F2E79000029414056696176692E47656F2E7A00002A0101010100010211004532204E6F6465204D6561737572656D656E7420666F7220612073696E676C652055450102003E414056696176692E55452E696400002B418056696176692E43656C6C2E696400002C41A056696176692E536C6963652E696400002D41404452422E5545546870446C00000341404452422E5545546870556C00000441805252552E50726255736564446C00000D41805252552E50726255736564556C00000E418052462E73657276696E672E696400002E41C052462E73657276696E672E5253525000002F41C052462E73657276696E672E52535251000030420052462E73657276696E672E525353494E52000031410052462E6E62312E6964000032414052462E6E62312E52535250000033414052462E6E62312E52535251000034418052462E6E62312E525353494E52000035410052462E6E62322E6964000036414052462E6E62322E52535250000037414052462E6E62322E52535251000038418052462E6E62322E525353494E52000039410052462E6E62332E696400003A414052462E6E62332E5253525000003B414052462E6E62332E5253525100003C418052462E6E62332E525353494E5200003D410052462E6E62342E696400003E414052462E6E62342E5253525000003F414052462E6E62342E52535251000040418052462E6E62342E525353494E52000041410052462E6E62352E6964000042414052462E6E62352E52535250000043414052462E6E62352E52535251000044418052462E6E62352E525353494E52000045410052462E6E62362E6964000046414052462E6E62362E52535250000047414052462E6E62362E52535251000048418052462E6E62362E525353494E52000049410052462E6E62372E696400004A414052462E6E62372E5253525000004B414052462E6E62372E5253525100004C418052462E6E62372E525353494E5200004D41C054422E546F744E6272556C496E697400001B420054422E496E7469616C4572724E6272446C000013424054422E526573696475616C4572724E6272446C00001A424054422E526573696475616C4572724E6272556C00002742C054422E546F744E6272446C496E697469616C2E5170736B00000F42E054422E546F744E6272446C496E697469616C2E313651616D00001042E054422E546F744E6272446C496E697469616C2E363451616D000011430054422E546F744E6272446C496E697469616C2E32353651616D00001242A054422E496E7469616C4572724E6272446C2E5170736B00001442C054422E496E7469616C4572724E6272446C2E313651616D00001542C054422E496E7469616C4572724E6272446C2E363451616D00001642E054422E496E7469616C4572724E6272446C2E32353651616D000017426054422E546F744E6272556C496E69742E5170736B00001C428054422E546F744E6272556C496E69742E313651616D00001D428054422E546F744E6272556C496E69742E363451616D00001E42A054422E546F744E6272556C496E69742E32353651616D00001F422054422E4572724E6272556C496E697469616C00002042C054422E4572724E6272556C496E697469616C2E5170736B00002142E054422E4572724E6272556C496E697469616C2E313651616D00002242E054422E4572724E6272556C496E697469616C2E363451616D000023430054422E4572724E6272556C496E697469616C2E32353651616D000024414056696176692E47656F2E78000028414056696176692E47656F2E79000029414056696176692E47656F2E7A00002A010101010001031600436F6E646974696F6E2D62617365642C2055452D6C6576656C204532204E6F6465204D6561737572656D656E740103003E414056696176692E55452E696400002B418056696176692E43656C6C2E696400002C41A056696176692E536C6963652E696400002D41404452422E5545546870446C00000341404452422E5545546870556C00000441805252552E50726255736564446C00000D41805252552E50726255736564556C00000E418052462E73657276696E672E696400002E41C052462E73657276696E672E5253525000002F41C052462E73657276696E672E52535251000030420052462E73657276696E672E525353494E52000031410052462E6E62312E6964000032414052462E6E62312E52535250000033414052462E6E62312E52535251000034418052462E6E62312E525353494E52000035410052462E6E62322E6964000036414052462E6E62322E52535250000037414052462E6E62322E52535251000038418052462E6E62322E525353494E52000039410052462E6E62332E696400003A414052462E6E62332E5253525000003B414052462E6E62332E5253525100003C418052462E6E62332E525353494E5200003D410052462E6E62342E696400003E414052462E6E62342E5253525000003F414052462E6E62342E52535251000040418052462E6E62342E525353494E52000041410052462E6E62352E6964000042414052462E6E62352E52535250000043414052462E6E62352E52535251000044418052462E6E62352E525353494E52000045410052462E6E62362E6964000046414052462E6E62362E52535250000047414052462E6E62362E52535251000048418052462E6E62362E525353494E52000049410052462E6E62372E696400004A414052462E6E62372E5253525000004B414052462E6E62372E5253525100004C418052462E6E62372E525353494E5200004D41C054422E546F744E6272556C496E697400001B420054422E496E7469616C4572724E6272446C000013424054422E526573696475616C4572724E6272446C00001A424054422E526573696475616C4572724E6272556C00002742C054422E546F744E6272446C496E697469616C2E5170736B00000F42E054422E546F744E6272446C496E697469616C2E313651616D00001042E054422E546F744E6272446C496E697469616C2E363451616D000011430054422E546F744E6272446C496E697469616C2E32353651616D00001242A054422E496E7469616C4572724E6272446C2E5170736B00001442C054422E496E7469616C4572724E6272446C2E313651616D00001542C054422E496E7469616C4572724E6272446C2E363451616D00001642E054422E496E7469616C4572724E6272446C2E32353651616D000017426054422E546F744E6272556C496E69742E5170736B00001C428054422E546F744E6272556C496E69742E313651616D00001D428054422E546F744E6272556C496E69742E363451616D00001E42A054422E546F744E6272556C496E69742E32353651616D00001F422054422E4572724E6272556C496E697469616C00002042C054422E4572724E6272556C496E697469616C2E5170736B00002142E054422E4572724E6272556C496E697469616C2E313651616D00002242E054422E4572724E6272556C496E697469616C2E363451616D000023430054422E4572724E6272556C496E697469616C2E32353651616D000024414056696176692E47656F2E78000028414056696176692E47656F2E79000029414056696176692E47656F2E7A00002A01010102")
	RanFuncDef, err := E2smRanFunctionDefinitionDecode(s)

	if err != nil {
		t.Error("Failed to decode RanFunctionDefinition, err = ", err)
	}
	Ranname := string("gNB_12345_6789")
	RanFuncId := int64(1)
	SubscriptionRequestPayload, err := GenerateSubscriptionRequestPayload(Ranname, RanFuncId, RanFuncDef)
	if err != nil {
		t.Error("Failed to generate subscription request payload, err = ", err)
	}
	fmt.Println(fmt.Sprintf("%+v", SubscriptionRequestPayload))
}

func TestGenerateActionDefinitionFormat1(t *testing.T) {
	s := string("68304F52414E2D4532534D2D4B504D000018312E332E362E312E342E312E35333134382E312E322E322E3208804B504D204D6F6E69746F72207630322E303001020001010700506572696F646963205265706F7274010108010109004532204E6F6465204D6561737572656D656E740101002A40A04E522D43474900000040A04E522D5043490000014100474E422D44552D494400000241404452422E5545546870446C00000341404452422E5545546870556C00000442C0516F73466C6F772E50646370506475566F6C756D65556C00000542C0516F73466C6F772E50646370506475566F6C756D65446C00000641605252432E436F6E6E4D65616E00000741405252432E436F6E6E4D617800000842605252432E496E616374697665436F6E6E4D65616E00000942405252432E496E616374697665436F6E6E4D617800000A41A05252552E507262417661696C446C00000B41A05252552E507262417661696C556C00000C41805252552E50726255736564446C00000D41805252552E50726255736564556C00000E42C054422E546F744E6272446C496E697469616C2E5170736B00000F42E054422E546F744E6272446C496E697469616C2E313651616D00001042E054422E546F744E6272446C496E697469616C2E363451616D000011430054422E546F744E6272446C496E697469616C2E32353651616D000012420054422E496E7469616C4572724E6272446C00001342A054422E496E7469616C4572724E6272446C2E5170736B00001442C054422E496E7469616C4572724E6272446C2E313651616D00001542C054422E496E7469616C4572724E6272446C2E363451616D00001642E054422E496E7469616C4572724E6272446C2E32353651616D000017418054422E546F744E6272446C2E58000018424054422E457272546F6C74616C4E6272446C2E58000019424054422E526573696475616C4572724E6272446C00001A41C054422E546F744E6272556C496E697400001B426054422E546F744E6272556C496E69742E5170736B00001C428054422E546F744E6272556C496E69742E313651616D00001D428054422E546F744E6272556C496E69742E363451616D00001E42A054422E546F744E6272556C496E69742E32353651616D00001F422054422E4572724E6272556C496E697469616C00002042C054422E4572724E6272556C496E697469616C2E5170736B00002142E054422E4572724E6272556C496E697469616C2E313651616D00002242E054422E4572724E6272556C496E697469616C2E363451616D000023430054422E4572724E6272556C496E697469616C2E32353651616D000024418054422E546F744E6272556C2E58000025424054422E457272546F6C74616C4E6272556C2E58000026424054422E526573696475616C4572724E6272556C000027414056696176692E47656F2E78000028414056696176692E47656F2E79000029414056696176692E47656F2E7A00002A0101010100010211004532204E6F6465204D6561737572656D656E7420666F7220612073696E676C652055450102003E414056696176692E55452E696400002B418056696176692E43656C6C2E696400002C41A056696176692E536C6963652E696400002D41404452422E5545546870446C00000341404452422E5545546870556C00000441805252552E50726255736564446C00000D41805252552E50726255736564556C00000E418052462E73657276696E672E696400002E41C052462E73657276696E672E5253525000002F41C052462E73657276696E672E52535251000030420052462E73657276696E672E525353494E52000031410052462E6E62312E6964000032414052462E6E62312E52535250000033414052462E6E62312E52535251000034418052462E6E62312E525353494E52000035410052462E6E62322E6964000036414052462E6E62322E52535250000037414052462E6E62322E52535251000038418052462E6E62322E525353494E52000039410052462E6E62332E696400003A414052462E6E62332E5253525000003B414052462E6E62332E5253525100003C418052462E6E62332E525353494E5200003D410052462E6E62342E696400003E414052462E6E62342E5253525000003F414052462E6E62342E52535251000040418052462E6E62342E525353494E52000041410052462E6E62352E6964000042414052462E6E62352E52535250000043414052462E6E62352E52535251000044418052462E6E62352E525353494E52000045410052462E6E62362E6964000046414052462E6E62362E52535250000047414052462E6E62362E52535251000048418052462E6E62362E525353494E52000049410052462E6E62372E696400004A414052462E6E62372E5253525000004B414052462E6E62372E5253525100004C418052462E6E62372E525353494E5200004D41C054422E546F744E6272556C496E697400001B420054422E496E7469616C4572724E6272446C000013424054422E526573696475616C4572724E6272446C00001A424054422E526573696475616C4572724E6272556C00002742C054422E546F744E6272446C496E697469616C2E5170736B00000F42E054422E546F744E6272446C496E697469616C2E313651616D00001042E054422E546F744E6272446C496E697469616C2E363451616D000011430054422E546F744E6272446C496E697469616C2E32353651616D00001242A054422E496E7469616C4572724E6272446C2E5170736B00001442C054422E496E7469616C4572724E6272446C2E313651616D00001542C054422E496E7469616C4572724E6272446C2E363451616D00001642E054422E496E7469616C4572724E6272446C2E32353651616D000017426054422E546F744E6272556C496E69742E5170736B00001C428054422E546F744E6272556C496E69742E313651616D00001D428054422E546F744E6272556C496E69742E363451616D00001E42A054422E546F744E6272556C496E69742E32353651616D00001F422054422E4572724E6272556C496E697469616C00002042C054422E4572724E6272556C496E697469616C2E5170736B00002142E054422E4572724E6272556C496E697469616C2E313651616D00002242E054422E4572724E6272556C496E697469616C2E363451616D000023430054422E4572724E6272556C496E697469616C2E32353651616D000024414056696176692E47656F2E78000028414056696176692E47656F2E79000029414056696176692E47656F2E7A00002A010101010001031600436F6E646974696F6E2D62617365642C2055452D6C6576656C204532204E6F6465204D6561737572656D656E740103003E414056696176692E55452E696400002B418056696176692E43656C6C2E696400002C41A056696176692E536C6963652E696400002D41404452422E5545546870446C00000341404452422E5545546870556C00000441805252552E50726255736564446C00000D41805252552E50726255736564556C00000E418052462E73657276696E672E696400002E41C052462E73657276696E672E5253525000002F41C052462E73657276696E672E52535251000030420052462E73657276696E672E525353494E52000031410052462E6E62312E6964000032414052462E6E62312E52535250000033414052462E6E62312E52535251000034418052462E6E62312E525353494E52000035410052462E6E62322E6964000036414052462E6E62322E52535250000037414052462E6E62322E52535251000038418052462E6E62322E525353494E52000039410052462E6E62332E696400003A414052462E6E62332E5253525000003B414052462E6E62332E5253525100003C418052462E6E62332E525353494E5200003D410052462E6E62342E696400003E414052462E6E62342E5253525000003F414052462E6E62342E52535251000040418052462E6E62342E525353494E52000041410052462E6E62352E6964000042414052462E6E62352E52535250000043414052462E6E62352E52535251000044418052462E6E62352E525353494E52000045410052462E6E62362E6964000046414052462E6E62362E52535250000047414052462E6E62362E52535251000048418052462E6E62362E525353494E52000049410052462E6E62372E696400004A414052462E6E62372E5253525000004B414052462E6E62372E5253525100004C418052462E6E62372E525353494E5200004D41C054422E546F744E6272556C496E697400001B420054422E496E7469616C4572724E6272446C000013424054422E526573696475616C4572724E6272446C00001A424054422E526573696475616C4572724E6272556C00002742C054422E546F744E6272446C496E697469616C2E5170736B00000F42E054422E546F744E6272446C496E697469616C2E313651616D00001042E054422E546F744E6272446C496E697469616C2E363451616D000011430054422E546F744E6272446C496E697469616C2E32353651616D00001242A054422E496E7469616C4572724E6272446C2E5170736B00001442C054422E496E7469616C4572724E6272446C2E313651616D00001542C054422E496E7469616C4572724E6272446C2E363451616D00001642E054422E496E7469616C4572724E6272446C2E32353651616D000017426054422E546F744E6272556C496E69742E5170736B00001C428054422E546F744E6272556C496E69742E313651616D00001D428054422E546F744E6272556C496E69742E363451616D00001E42A054422E546F744E6272556C496E69742E32353651616D00001F422054422E4572724E6272556C496E697469616C00002042C054422E4572724E6272556C496E697469616C2E5170736B00002142E054422E4572724E6272556C496E697469616C2E313651616D00002242E054422E4572724E6272556C496E697469616C2E363451616D000023430054422E4572724E6272556C496E697469616C2E32353651616D000024414056696176692E47656F2E78000028414056696176692E47656F2E79000029414056696176692E47656F2E7A00002A01010102")
	RanFuncDef, err := E2smRanFunctionDefinitionDecode(s)

	if err != nil {
		t.Error("Failed to decode RanFunctionDefinition, err = ", err)
	}

	ActionDefinition, err := GenerateActionDefinitionFormat1(RanFuncDef.ric_ReportStyle_List[0])
	if err != nil {
		t.Error("Failed to GenerateActionDefinitionFormat1, err = ", err)
	}
	fmt.Println(fmt.Sprintf("%+v", ActionDefinition))
}