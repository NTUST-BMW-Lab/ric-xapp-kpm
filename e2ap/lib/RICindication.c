/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-CommonDataTypes"
 * 	found in "O-RAN.WG3.E2APv2.01.asn1"
 * 	`asn1c -pdu=auto -fcompound-names -fno-include-deps -findirect-choice -gen-PER -gen-OER -no-gen-example`
 */

#include "RICindication.h"

static asn_TYPE_member_t asn_MBR_RICindication_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct RICindication, protocolIEs),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolIE_Container_185P7,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"protocolIEs"
		},
};
static const ber_tlv_tag_t asn_DEF_RICindication_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_RICindication_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* protocolIEs */
};
static asn_SEQUENCE_specifics_t asn_SPC_RICindication_specs_1 = {
	sizeof(struct RICindication),
	offsetof(struct RICindication, _asn_ctx),
	asn_MAP_RICindication_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_RICindication = {
	"RICindication",
	"RICindication",
	&asn_OP_SEQUENCE,
	asn_DEF_RICindication_tags_1,
	sizeof(asn_DEF_RICindication_tags_1)
		/sizeof(asn_DEF_RICindication_tags_1[0]), /* 1 */
	asn_DEF_RICindication_tags_1,	/* Same as above */
	sizeof(asn_DEF_RICindication_tags_1)
		/sizeof(asn_DEF_RICindication_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_RICindication_1,
	1,	/* Elements count */
	&asn_SPC_RICindication_specs_1	/* Additional specs */
};

