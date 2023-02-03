/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-KPM-IEs"
 * 	found in "O-RAN.WG3.E2SM-KPM-v02.01.asn1"
 * 	`asn1c -pdu=auto -fcompound-names -fno-include-deps -findirect-choice -gen-PER -gen-OER -no-gen-example`
 */

#ifndef	_TestCond_Value_H_
#define	_TestCond_Value_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <BOOLEAN.h>
#include <BIT_STRING.h>
#include <OCTET_STRING.h>
#include <PrintableString.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum TestCond_Value_PR {
	TestCond_Value_PR_NOTHING,	/* No components present */
	TestCond_Value_PR_valueInt,
	TestCond_Value_PR_valueEnum,
	TestCond_Value_PR_valueBool,
	TestCond_Value_PR_valueBitS,
	TestCond_Value_PR_valueOctS,
	TestCond_Value_PR_valuePrtS
	/* Extensions may appear below */
	
} TestCond_Value_PR;

/* TestCond-Value */
typedef struct TestCond_Value {
	TestCond_Value_PR present;
	union TestCond_Value_u {
		long	 valueInt;
		long	 valueEnum;
		BOOLEAN_t	 valueBool;
		BIT_STRING_t	 valueBitS;
		OCTET_STRING_t	 valueOctS;
		PrintableString_t	 valuePrtS;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TestCond_Value_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TestCond_Value;
extern asn_CHOICE_specifics_t asn_SPC_TestCond_Value_specs_1;
extern asn_TYPE_member_t asn_MBR_TestCond_Value_1[6];
extern asn_per_constraints_t asn_PER_type_TestCond_Value_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _TestCond_Value_H_ */
#include <asn_internal.h>
