/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-KPM-IEs"
 * 	found in "O-RAN.WG3.E2SM-KPM-v02.01.asn1"
 * 	`asn1c -pdu=auto -fcompound-names -fno-include-deps -findirect-choice -gen-PER -gen-OER -no-gen-example`
 */

#ifndef	_E2SM_KPM_IndicationMessage_Format3_H_
#define	_E2SM_KPM_IndicationMessage_Format3_H_


#include <asn_application.h>

/* Including external dependencies */
#include "UEMeasurementReportList.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* E2SM-KPM-IndicationMessage-Format3 */
typedef struct E2SM_KPM_IndicationMessage_Format3 {
	UEMeasurementReportList_t	 ueMeasReportList;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_KPM_IndicationMessage_Format3_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2SM_KPM_IndicationMessage_Format3;
extern asn_SEQUENCE_specifics_t asn_SPC_E2SM_KPM_IndicationMessage_Format3_specs_1;
extern asn_TYPE_member_t asn_MBR_E2SM_KPM_IndicationMessage_Format3_1[1];

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_KPM_IndicationMessage_Format3_H_ */
#include <asn_internal.h>
