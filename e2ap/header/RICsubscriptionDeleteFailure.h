/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-CommonDataTypes"
 * 	found in "O-RAN.WG3.E2APv2.01.asn1"
 * 	`asn1c -pdu=auto -fcompound-names -fno-include-deps -findirect-choice -gen-PER -gen-OER -no-gen-example`
 */

#ifndef	_RICsubscriptionDeleteFailure_H_
#define	_RICsubscriptionDeleteFailure_H_


#include <asn_application.h>

/* Including external dependencies */
#include "ProtocolIE-Container.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RICsubscriptionDeleteFailure */
typedef struct RICsubscriptionDeleteFailure {
	ProtocolIE_Container_185P5_t	 protocolIEs;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RICsubscriptionDeleteFailure_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RICsubscriptionDeleteFailure;

#ifdef __cplusplus
}
#endif

#endif	/* _RICsubscriptionDeleteFailure_H_ */
#include <asn_internal.h>
