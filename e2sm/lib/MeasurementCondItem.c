/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-KPM-IEs"
 * 	found in "O-RAN.WG3.E2SM-KPM-v02.01.asn1"
 * 	`asn1c -pdu=auto -fcompound-names -fno-include-deps -findirect-choice -gen-PER -gen-OER -no-gen-example`
 */

#include "MeasurementCondItem.h"

asn_TYPE_member_t asn_MBR_MeasurementCondItem_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct MeasurementCondItem, measType),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_MeasurementType,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"measType"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct MeasurementCondItem, matchingCond),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MatchingCondList,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"matchingCond"
		},
};
static const ber_tlv_tag_t asn_DEF_MeasurementCondItem_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_MeasurementCondItem_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* measType */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* matchingCond */
};
asn_SEQUENCE_specifics_t asn_SPC_MeasurementCondItem_specs_1 = {
	sizeof(struct MeasurementCondItem),
	offsetof(struct MeasurementCondItem, _asn_ctx),
	asn_MAP_MeasurementCondItem_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	2,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_MeasurementCondItem = {
	"MeasurementCondItem",
	"MeasurementCondItem",
	&asn_OP_SEQUENCE,
	asn_DEF_MeasurementCondItem_tags_1,
	sizeof(asn_DEF_MeasurementCondItem_tags_1)
		/sizeof(asn_DEF_MeasurementCondItem_tags_1[0]), /* 1 */
	asn_DEF_MeasurementCondItem_tags_1,	/* Same as above */
	sizeof(asn_DEF_MeasurementCondItem_tags_1)
		/sizeof(asn_DEF_MeasurementCondItem_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_MeasurementCondItem_1,
	2,	/* Elements count */
	&asn_SPC_MeasurementCondItem_specs_1	/* Additional specs */
};

