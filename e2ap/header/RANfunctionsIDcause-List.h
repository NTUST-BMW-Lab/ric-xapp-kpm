/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-CommonDataTypes"
 * 	found in "O-RAN.WG3.E2APv2.01.asn1"
 * 	`asn1c -pdu=auto -fcompound-names -fno-include-deps -findirect-choice -gen-PER -gen-OER -no-gen-example`
 */

#ifndef	_RANfunctionsIDcause_List_H_
#define	_RANfunctionsIDcause_List_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolIE_SingleContainer;

/* RANfunctionsIDcause-List */
typedef struct RANfunctionsIDcause_List {
	A_SEQUENCE_OF(struct ProtocolIE_SingleContainer) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANfunctionsIDcause_List_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANfunctionsIDcause_List;
extern asn_SET_OF_specifics_t asn_SPC_RANfunctionsIDcause_List_specs_1;
extern asn_TYPE_member_t asn_MBR_RANfunctionsIDcause_List_1[1];
extern asn_per_constraints_t asn_PER_type_RANfunctionsIDcause_List_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _RANfunctionsIDcause_List_H_ */
#include <asn_internal.h>
