/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-KPM-IEs"
 * 	found in "O-RAN.WG3.E2SM-KPM-v02.01.asn1"
 * 	`asn1c -pdu=auto -fcompound-names -fno-include-deps -findirect-choice -gen-PER -gen-OER -no-gen-example`
 */

#include "MeasurementLabel.h"

#include "S-NSSAI.h"
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static int
memb_aRPmax_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 15)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_aRPmin_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 15)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_bitrateRange_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 65535)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_layerMU_MIMO_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 65535)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_distBinX_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 65535)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_distBinY_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 65535)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_distBinZ_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 65535)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_oer_constraints_t asn_OER_type_noLabel_constr_2 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_noLabel_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  0,  0,  0,  0 }	/* (0..0,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_type_sUM_constr_16 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_sUM_constr_16 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  0,  0,  0,  0 }	/* (0..0,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_type_preLabelOverride_constr_22 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_preLabelOverride_constr_22 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  0,  0,  0,  0 }	/* (0..0,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_type_startEndInd_constr_25 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_startEndInd_constr_25 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  1,  1,  0,  1 }	/* (0..1,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_type_min_constr_29 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_min_constr_29 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  0,  0,  0,  0 }	/* (0..0,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_type_max_constr_32 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_max_constr_32 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  0,  0,  0,  0 }	/* (0..0,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_type_avg_constr_35 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_avg_constr_35 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  0,  0,  0,  0 }	/* (0..0,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_aRPmax_constr_12 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_memb_aRPmax_constr_12 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  4,  4,  1,  15 }	/* (1..15,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_aRPmin_constr_13 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_memb_aRPmin_constr_13 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  4,  4,  1,  15 }	/* (1..15,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_bitrateRange_constr_14 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_memb_bitrateRange_constr_14 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  16,  16,  1,  65535 }	/* (1..65535,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_layerMU_MIMO_constr_15 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_memb_layerMU_MIMO_constr_15 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  16,  16,  1,  65535 }	/* (1..65535,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_distBinX_constr_19 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_memb_distBinX_constr_19 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  16,  16,  1,  65535 }	/* (1..65535,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_distBinY_constr_20 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_memb_distBinY_constr_20 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  16,  16,  1,  65535 }	/* (1..65535,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_distBinZ_constr_21 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_memb_distBinZ_constr_21 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  16,  16,  1,  65535 }	/* (1..65535,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_noLabel_value2enum_2[] = {
	{ 0,	4,	"true" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_noLabel_enum2value_2[] = {
	0	/* true(0) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_noLabel_specs_2 = {
	asn_MAP_noLabel_value2enum_2,	/* "tag" => N; sorted by tag */
	asn_MAP_noLabel_enum2value_2,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	2,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_noLabel_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_noLabel_2 = {
	"noLabel",
	"noLabel",
	&asn_OP_NativeEnumerated,
	asn_DEF_noLabel_tags_2,
	sizeof(asn_DEF_noLabel_tags_2)
		/sizeof(asn_DEF_noLabel_tags_2[0]) - 1, /* 1 */
	asn_DEF_noLabel_tags_2,	/* Same as above */
	sizeof(asn_DEF_noLabel_tags_2)
		/sizeof(asn_DEF_noLabel_tags_2[0]), /* 2 */
	{ &asn_OER_type_noLabel_constr_2, &asn_PER_type_noLabel_constr_2, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_noLabel_specs_2	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_sUM_value2enum_16[] = {
	{ 0,	4,	"true" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_sUM_enum2value_16[] = {
	0	/* true(0) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_sUM_specs_16 = {
	asn_MAP_sUM_value2enum_16,	/* "tag" => N; sorted by tag */
	asn_MAP_sUM_enum2value_16,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	2,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_sUM_tags_16[] = {
	(ASN_TAG_CLASS_CONTEXT | (12 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_sUM_16 = {
	"sUM",
	"sUM",
	&asn_OP_NativeEnumerated,
	asn_DEF_sUM_tags_16,
	sizeof(asn_DEF_sUM_tags_16)
		/sizeof(asn_DEF_sUM_tags_16[0]) - 1, /* 1 */
	asn_DEF_sUM_tags_16,	/* Same as above */
	sizeof(asn_DEF_sUM_tags_16)
		/sizeof(asn_DEF_sUM_tags_16[0]), /* 2 */
	{ &asn_OER_type_sUM_constr_16, &asn_PER_type_sUM_constr_16, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_sUM_specs_16	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_preLabelOverride_value2enum_22[] = {
	{ 0,	4,	"true" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_preLabelOverride_enum2value_22[] = {
	0	/* true(0) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_preLabelOverride_specs_22 = {
	asn_MAP_preLabelOverride_value2enum_22,	/* "tag" => N; sorted by tag */
	asn_MAP_preLabelOverride_enum2value_22,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	2,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_preLabelOverride_tags_22[] = {
	(ASN_TAG_CLASS_CONTEXT | (16 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_preLabelOverride_22 = {
	"preLabelOverride",
	"preLabelOverride",
	&asn_OP_NativeEnumerated,
	asn_DEF_preLabelOverride_tags_22,
	sizeof(asn_DEF_preLabelOverride_tags_22)
		/sizeof(asn_DEF_preLabelOverride_tags_22[0]) - 1, /* 1 */
	asn_DEF_preLabelOverride_tags_22,	/* Same as above */
	sizeof(asn_DEF_preLabelOverride_tags_22)
		/sizeof(asn_DEF_preLabelOverride_tags_22[0]), /* 2 */
	{ &asn_OER_type_preLabelOverride_constr_22, &asn_PER_type_preLabelOverride_constr_22, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_preLabelOverride_specs_22	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_startEndInd_value2enum_25[] = {
	{ 0,	5,	"start" },
	{ 1,	3,	"end" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_startEndInd_enum2value_25[] = {
	1,	/* end(1) */
	0	/* start(0) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_startEndInd_specs_25 = {
	asn_MAP_startEndInd_value2enum_25,	/* "tag" => N; sorted by tag */
	asn_MAP_startEndInd_enum2value_25,	/* N => "tag"; sorted by N */
	2,	/* Number of elements in the maps */
	3,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_startEndInd_tags_25[] = {
	(ASN_TAG_CLASS_CONTEXT | (17 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_startEndInd_25 = {
	"startEndInd",
	"startEndInd",
	&asn_OP_NativeEnumerated,
	asn_DEF_startEndInd_tags_25,
	sizeof(asn_DEF_startEndInd_tags_25)
		/sizeof(asn_DEF_startEndInd_tags_25[0]) - 1, /* 1 */
	asn_DEF_startEndInd_tags_25,	/* Same as above */
	sizeof(asn_DEF_startEndInd_tags_25)
		/sizeof(asn_DEF_startEndInd_tags_25[0]), /* 2 */
	{ &asn_OER_type_startEndInd_constr_25, &asn_PER_type_startEndInd_constr_25, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_startEndInd_specs_25	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_min_value2enum_29[] = {
	{ 0,	4,	"true" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_min_enum2value_29[] = {
	0	/* true(0) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_min_specs_29 = {
	asn_MAP_min_value2enum_29,	/* "tag" => N; sorted by tag */
	asn_MAP_min_enum2value_29,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	2,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_min_tags_29[] = {
	(ASN_TAG_CLASS_CONTEXT | (18 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_min_29 = {
	"min",
	"min",
	&asn_OP_NativeEnumerated,
	asn_DEF_min_tags_29,
	sizeof(asn_DEF_min_tags_29)
		/sizeof(asn_DEF_min_tags_29[0]) - 1, /* 1 */
	asn_DEF_min_tags_29,	/* Same as above */
	sizeof(asn_DEF_min_tags_29)
		/sizeof(asn_DEF_min_tags_29[0]), /* 2 */
	{ &asn_OER_type_min_constr_29, &asn_PER_type_min_constr_29, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_min_specs_29	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_max_value2enum_32[] = {
	{ 0,	4,	"true" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_max_enum2value_32[] = {
	0	/* true(0) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_max_specs_32 = {
	asn_MAP_max_value2enum_32,	/* "tag" => N; sorted by tag */
	asn_MAP_max_enum2value_32,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	2,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_max_tags_32[] = {
	(ASN_TAG_CLASS_CONTEXT | (19 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_max_32 = {
	"max",
	"max",
	&asn_OP_NativeEnumerated,
	asn_DEF_max_tags_32,
	sizeof(asn_DEF_max_tags_32)
		/sizeof(asn_DEF_max_tags_32[0]) - 1, /* 1 */
	asn_DEF_max_tags_32,	/* Same as above */
	sizeof(asn_DEF_max_tags_32)
		/sizeof(asn_DEF_max_tags_32[0]), /* 2 */
	{ &asn_OER_type_max_constr_32, &asn_PER_type_max_constr_32, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_max_specs_32	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_avg_value2enum_35[] = {
	{ 0,	4,	"true" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_avg_enum2value_35[] = {
	0	/* true(0) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_avg_specs_35 = {
	asn_MAP_avg_value2enum_35,	/* "tag" => N; sorted by tag */
	asn_MAP_avg_enum2value_35,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	2,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_avg_tags_35[] = {
	(ASN_TAG_CLASS_CONTEXT | (20 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_avg_35 = {
	"avg",
	"avg",
	&asn_OP_NativeEnumerated,
	asn_DEF_avg_tags_35,
	sizeof(asn_DEF_avg_tags_35)
		/sizeof(asn_DEF_avg_tags_35[0]) - 1, /* 1 */
	asn_DEF_avg_tags_35,	/* Same as above */
	sizeof(asn_DEF_avg_tags_35)
		/sizeof(asn_DEF_avg_tags_35[0]), /* 2 */
	{ &asn_OER_type_avg_constr_35, &asn_PER_type_avg_constr_35, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_avg_specs_35	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_MeasurementLabel_1[] = {
	{ ATF_POINTER, 21, offsetof(struct MeasurementLabel, noLabel),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_noLabel_2,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"noLabel"
		},
	{ ATF_POINTER, 20, offsetof(struct MeasurementLabel, plmnID),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PLMNIdentity,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"plmnID"
		},
	{ ATF_POINTER, 19, offsetof(struct MeasurementLabel, sliceID),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_S_NSSAI,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"sliceID"
		},
	{ ATF_POINTER, 18, offsetof(struct MeasurementLabel, fiveQI),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_FiveQI,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"fiveQI"
		},
	{ ATF_POINTER, 17, offsetof(struct MeasurementLabel, qFI),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_QosFlowIdentifier,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"qFI"
		},
	{ ATF_POINTER, 16, offsetof(struct MeasurementLabel, qCI),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_QCI,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"qCI"
		},
	{ ATF_POINTER, 15, offsetof(struct MeasurementLabel, qCImax),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_QCI,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"qCImax"
		},
	{ ATF_POINTER, 14, offsetof(struct MeasurementLabel, qCImin),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_QCI,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"qCImin"
		},
	{ ATF_POINTER, 13, offsetof(struct MeasurementLabel, aRPmax),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_aRPmax_constr_12, &asn_PER_memb_aRPmax_constr_12,  memb_aRPmax_constraint_1 },
		0, 0, /* No default value */
		"aRPmax"
		},
	{ ATF_POINTER, 12, offsetof(struct MeasurementLabel, aRPmin),
		(ASN_TAG_CLASS_CONTEXT | (9 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_aRPmin_constr_13, &asn_PER_memb_aRPmin_constr_13,  memb_aRPmin_constraint_1 },
		0, 0, /* No default value */
		"aRPmin"
		},
	{ ATF_POINTER, 11, offsetof(struct MeasurementLabel, bitrateRange),
		(ASN_TAG_CLASS_CONTEXT | (10 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_bitrateRange_constr_14, &asn_PER_memb_bitrateRange_constr_14,  memb_bitrateRange_constraint_1 },
		0, 0, /* No default value */
		"bitrateRange"
		},
	{ ATF_POINTER, 10, offsetof(struct MeasurementLabel, layerMU_MIMO),
		(ASN_TAG_CLASS_CONTEXT | (11 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_layerMU_MIMO_constr_15, &asn_PER_memb_layerMU_MIMO_constr_15,  memb_layerMU_MIMO_constraint_1 },
		0, 0, /* No default value */
		"layerMU-MIMO"
		},
	{ ATF_POINTER, 9, offsetof(struct MeasurementLabel, sUM),
		(ASN_TAG_CLASS_CONTEXT | (12 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_sUM_16,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"sUM"
		},
	{ ATF_POINTER, 8, offsetof(struct MeasurementLabel, distBinX),
		(ASN_TAG_CLASS_CONTEXT | (13 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_distBinX_constr_19, &asn_PER_memb_distBinX_constr_19,  memb_distBinX_constraint_1 },
		0, 0, /* No default value */
		"distBinX"
		},
	{ ATF_POINTER, 7, offsetof(struct MeasurementLabel, distBinY),
		(ASN_TAG_CLASS_CONTEXT | (14 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_distBinY_constr_20, &asn_PER_memb_distBinY_constr_20,  memb_distBinY_constraint_1 },
		0, 0, /* No default value */
		"distBinY"
		},
	{ ATF_POINTER, 6, offsetof(struct MeasurementLabel, distBinZ),
		(ASN_TAG_CLASS_CONTEXT | (15 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_distBinZ_constr_21, &asn_PER_memb_distBinZ_constr_21,  memb_distBinZ_constraint_1 },
		0, 0, /* No default value */
		"distBinZ"
		},
	{ ATF_POINTER, 5, offsetof(struct MeasurementLabel, preLabelOverride),
		(ASN_TAG_CLASS_CONTEXT | (16 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_preLabelOverride_22,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"preLabelOverride"
		},
	{ ATF_POINTER, 4, offsetof(struct MeasurementLabel, startEndInd),
		(ASN_TAG_CLASS_CONTEXT | (17 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_startEndInd_25,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"startEndInd"
		},
	{ ATF_POINTER, 3, offsetof(struct MeasurementLabel, min),
		(ASN_TAG_CLASS_CONTEXT | (18 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_min_29,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"min"
		},
	{ ATF_POINTER, 2, offsetof(struct MeasurementLabel, max),
		(ASN_TAG_CLASS_CONTEXT | (19 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_max_32,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"max"
		},
	{ ATF_POINTER, 1, offsetof(struct MeasurementLabel, avg),
		(ASN_TAG_CLASS_CONTEXT | (20 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_avg_35,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"avg"
		},
};
static const int asn_MAP_MeasurementLabel_oms_1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
static const ber_tlv_tag_t asn_DEF_MeasurementLabel_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_MeasurementLabel_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* noLabel */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* plmnID */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* sliceID */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* fiveQI */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* qFI */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* qCI */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* qCImax */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* qCImin */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 }, /* aRPmax */
    { (ASN_TAG_CLASS_CONTEXT | (9 << 2)), 9, 0, 0 }, /* aRPmin */
    { (ASN_TAG_CLASS_CONTEXT | (10 << 2)), 10, 0, 0 }, /* bitrateRange */
    { (ASN_TAG_CLASS_CONTEXT | (11 << 2)), 11, 0, 0 }, /* layerMU-MIMO */
    { (ASN_TAG_CLASS_CONTEXT | (12 << 2)), 12, 0, 0 }, /* sUM */
    { (ASN_TAG_CLASS_CONTEXT | (13 << 2)), 13, 0, 0 }, /* distBinX */
    { (ASN_TAG_CLASS_CONTEXT | (14 << 2)), 14, 0, 0 }, /* distBinY */
    { (ASN_TAG_CLASS_CONTEXT | (15 << 2)), 15, 0, 0 }, /* distBinZ */
    { (ASN_TAG_CLASS_CONTEXT | (16 << 2)), 16, 0, 0 }, /* preLabelOverride */
    { (ASN_TAG_CLASS_CONTEXT | (17 << 2)), 17, 0, 0 }, /* startEndInd */
    { (ASN_TAG_CLASS_CONTEXT | (18 << 2)), 18, 0, 0 }, /* min */
    { (ASN_TAG_CLASS_CONTEXT | (19 << 2)), 19, 0, 0 }, /* max */
    { (ASN_TAG_CLASS_CONTEXT | (20 << 2)), 20, 0, 0 } /* avg */
};
asn_SEQUENCE_specifics_t asn_SPC_MeasurementLabel_specs_1 = {
	sizeof(struct MeasurementLabel),
	offsetof(struct MeasurementLabel, _asn_ctx),
	asn_MAP_MeasurementLabel_tag2el_1,
	21,	/* Count of tags in the map */
	asn_MAP_MeasurementLabel_oms_1,	/* Optional members */
	21, 0,	/* Root/Additions */
	21,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_MeasurementLabel = {
	"MeasurementLabel",
	"MeasurementLabel",
	&asn_OP_SEQUENCE,
	asn_DEF_MeasurementLabel_tags_1,
	sizeof(asn_DEF_MeasurementLabel_tags_1)
		/sizeof(asn_DEF_MeasurementLabel_tags_1[0]), /* 1 */
	asn_DEF_MeasurementLabel_tags_1,	/* Same as above */
	sizeof(asn_DEF_MeasurementLabel_tags_1)
		/sizeof(asn_DEF_MeasurementLabel_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_MeasurementLabel_1,
	21,	/* Elements count */
	&asn_SPC_MeasurementLabel_specs_1	/* Additional specs */
};

