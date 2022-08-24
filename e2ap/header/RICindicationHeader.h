/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-CommonDataTypes"
 * 	found in "O-RAN.WG3.E2APv2.01.asn1"
 * 	`asn1c -pdu=auto -fcompound-names -fno-include-deps -findirect-choice -gen-PER -gen-OER -no-gen-example`
 */

#ifndef	_RICindicationHeader_H_
#define	_RICindicationHeader_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RICindicationHeader */
typedef OCTET_STRING_t	 RICindicationHeader_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RICindicationHeader;
asn_struct_free_f RICindicationHeader_free;
asn_struct_print_f RICindicationHeader_print;
asn_constr_check_f RICindicationHeader_constraint;
ber_type_decoder_f RICindicationHeader_decode_ber;
der_type_encoder_f RICindicationHeader_encode_der;
xer_type_decoder_f RICindicationHeader_decode_xer;
xer_type_encoder_f RICindicationHeader_encode_xer;
oer_type_decoder_f RICindicationHeader_decode_oer;
oer_type_encoder_f RICindicationHeader_encode_oer;
per_type_decoder_f RICindicationHeader_decode_uper;
per_type_encoder_f RICindicationHeader_encode_uper;
per_type_decoder_f RICindicationHeader_decode_aper;
per_type_encoder_f RICindicationHeader_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _RICindicationHeader_H_ */
#include <asn_internal.h>
