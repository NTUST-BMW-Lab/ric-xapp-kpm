/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-CommonDataTypes"
 * 	found in "O-RAN.WG3.E2APv2.01.asn1"
 * 	`asn1c -pdu=auto -fcompound-names -fno-include-deps -findirect-choice -gen-PER -gen-OER -no-gen-example`
 */

#ifndef	_AMFName_H_
#define	_AMFName_H_


#include <asn_application.h>

/* Including external dependencies */
#include <PrintableString.h>

#ifdef __cplusplus
extern "C" {
#endif

/* AMFName */
typedef PrintableString_t	 AMFName_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_AMFName_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_AMFName;
asn_struct_free_f AMFName_free;
asn_struct_print_f AMFName_print;
asn_constr_check_f AMFName_constraint;
ber_type_decoder_f AMFName_decode_ber;
der_type_encoder_f AMFName_encode_der;
xer_type_decoder_f AMFName_decode_xer;
xer_type_encoder_f AMFName_encode_xer;
oer_type_decoder_f AMFName_decode_oer;
oer_type_encoder_f AMFName_encode_oer;
per_type_decoder_f AMFName_decode_uper;
per_type_encoder_f AMFName_encode_uper;
per_type_decoder_f AMFName_decode_aper;
per_type_encoder_f AMFName_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _AMFName_H_ */
#include <asn_internal.h>
