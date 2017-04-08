/* ModeloDB.c generated by valac 0.34.7, the Vala compiler
 * generated from ModeloDB.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <sqlite3.h>
#include <stdio.h>
#include "base.h"
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <gee.h>


#define AUMBRALES_TYPE_MODELO_DB (aumbrales_modelo_db_get_type ())
#define AUMBRALES_MODELO_DB(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), AUMBRALES_TYPE_MODELO_DB, AumbralesModeloDB))
#define AUMBRALES_MODELO_DB_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), AUMBRALES_TYPE_MODELO_DB, AumbralesModeloDBClass))
#define AUMBRALES_IS_MODELO_DB(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), AUMBRALES_TYPE_MODELO_DB))
#define AUMBRALES_IS_MODELO_DB_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), AUMBRALES_TYPE_MODELO_DB))
#define AUMBRALES_MODELO_DB_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), AUMBRALES_TYPE_MODELO_DB, AumbralesModeloDBClass))

typedef struct _AumbralesModeloDB AumbralesModeloDB;
typedef struct _AumbralesModeloDBClass AumbralesModeloDBClass;
typedef struct _AumbralesModeloDBPrivate AumbralesModeloDBPrivate;
#define _sqlite3_close0(var) ((var == NULL) ? NULL : (var = (sqlite3_close (var), NULL)))
#define _sqlite3_finalize0(var) ((var == NULL) ? NULL : (var = (sqlite3_finalize (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define __g_list_free__g_object_unref0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__g_object_unref0_ (var), NULL)))
#define _vala_assert(expr, msg) if G_LIKELY (expr) ; else g_assertion_message_expr (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);
#define _vala_return_if_fail(expr, msg) if G_LIKELY (expr) ; else { g_return_if_fail_warning (G_LOG_DOMAIN, G_STRFUNC, msg); return; }
#define _vala_return_val_if_fail(expr, msg, val) if G_LIKELY (expr) ; else { g_return_if_fail_warning (G_LOG_DOMAIN, G_STRFUNC, msg); return val; }
#define _vala_warn_if_fail(expr, msg) if G_LIKELY (expr) ; else g_warn_message (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);

struct _AumbralesModeloDB {
	GObject parent_instance;
	AumbralesModeloDBPrivate * priv;
};

struct _AumbralesModeloDBClass {
	GObjectClass parent_class;
};

struct _AumbralesModeloDBPrivate {
	sqlite3* db;
	sqlite3_stmt* stmt;
};


static gpointer aumbrales_modelo_db_parent_class = NULL;

GType aumbrales_modelo_db_get_type (void) G_GNUC_CONST;
#define AUMBRALES_MODELO_DB_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), AUMBRALES_TYPE_MODELO_DB, AumbralesModeloDBPrivate))
enum  {
	AUMBRALES_MODELO_DB_DUMMY_PROPERTY
};
AumbralesModeloDB* aumbrales_modelo_db_new (void);
AumbralesModeloDB* aumbrales_modelo_db_construct (GType object_type);
GList* aumbrales_modelo_db_getCiudades (AumbralesModeloDB* self);
static void _g_object_unref0_ (gpointer var);
static void _g_list_free__g_object_unref0_ (GList* self);
AumbralesBaseCiudad* aumbrales_modelo_db_getCiudad (AumbralesModeloDB* self, gint id);
GeeHashMap* aumbrales_modelo_db_getConexiones (AumbralesModeloDB* self);
static gdouble* _double_dup (gdouble* self);
static void aumbrales_modelo_db_finalize (GObject* obj);


AumbralesModeloDB* aumbrales_modelo_db_construct (GType object_type) {
	AumbralesModeloDB * self = NULL;
	gint ec = 0;
	sqlite3* _tmp0_ = NULL;
	gint _tmp1_ = 0;
	gint _tmp2_ = 0;
	self = (AumbralesModeloDB*) g_object_new (object_type, NULL);
	_tmp1_ = sqlite3_open ("ciudades", &_tmp0_);
	_sqlite3_close0 (self->priv->db);
	self->priv->db = _tmp0_;
	ec = _tmp1_;
	_tmp2_ = ec;
	if (_tmp2_ != SQLITE_OK) {
		FILE* _tmp3_ = NULL;
		sqlite3* _tmp4_ = NULL;
		gint _tmp5_ = 0;
		sqlite3* _tmp6_ = NULL;
		const gchar* _tmp7_ = NULL;
		_tmp3_ = stderr;
		_tmp4_ = self->priv->db;
		_tmp5_ = sqlite3_errcode (_tmp4_);
		_tmp6_ = self->priv->db;
		_tmp7_ = sqlite3_errmsg (_tmp6_);
		fprintf (_tmp3_, "Can't open database: %d: %s\n", _tmp5_, _tmp7_);
	}
	return self;
}


AumbralesModeloDB* aumbrales_modelo_db_new (void) {
	return aumbrales_modelo_db_construct (AUMBRALES_TYPE_MODELO_DB);
}


static gdouble double_parse (const gchar* str) {
	gdouble result = 0.0;
	const gchar* _tmp0_ = NULL;
	gdouble _tmp1_ = 0.0;
	g_return_val_if_fail (str != NULL, 0.0);
	_tmp0_ = str;
	_tmp1_ = g_ascii_strtod (_tmp0_, NULL);
	result = _tmp1_;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _g_object_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}


static void _g_list_free__g_object_unref0_ (GList* self) {
	g_list_foreach (self, (GFunc) _g_object_unref0_, NULL);
	g_list_free (self);
}


GList* aumbrales_modelo_db_getCiudades (AumbralesModeloDB* self) {
	GList* result = NULL;
	GList* ci = NULL;
	static const char prepared_query_str[] = "SELECT * FROM cities;";
	gint ec = 0;
	sqlite3* _tmp0_ = NULL;
	gint _tmp1_ = 0;
	gint _tmp2_ = 0;
	sqlite3_stmt* _tmp3_ = NULL;
	gint _tmp4_ = 0;
	gint _tmp5_ = 0;
	gint cols = 0;
	sqlite3_stmt* _tmp11_ = NULL;
	gint _tmp12_ = 0;
	sqlite3_stmt* _tmp52_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	ci = NULL;
	_tmp0_ = self->priv->db;
	_tmp1_ = strlen (prepared_query_str);
	_tmp2_ = _tmp1_;
	_tmp4_ = sqlite3_prepare_v2 (_tmp0_, prepared_query_str, _tmp2_, &_tmp3_, NULL);
	_sqlite3_finalize0 (self->priv->stmt);
	self->priv->stmt = _tmp3_;
	ec = _tmp4_;
	_tmp5_ = ec;
	if (_tmp5_ != SQLITE_OK) {
		FILE* _tmp6_ = NULL;
		sqlite3* _tmp7_ = NULL;
		gint _tmp8_ = 0;
		sqlite3* _tmp9_ = NULL;
		const gchar* _tmp10_ = NULL;
		_tmp6_ = stderr;
		_tmp7_ = self->priv->db;
		_tmp8_ = sqlite3_errcode (_tmp7_);
		_tmp9_ = self->priv->db;
		_tmp10_ = sqlite3_errmsg (_tmp9_);
		fprintf (_tmp6_, "Error: %d: %s\n", _tmp8_, _tmp10_);
	}
	_tmp11_ = self->priv->stmt;
	_tmp12_ = sqlite3_column_count (_tmp11_);
	cols = _tmp12_;
	while (TRUE) {
		sqlite3_stmt* _tmp13_ = NULL;
		gint _tmp14_ = 0;
		AumbralesBaseCiudad* c = NULL;
		AumbralesBaseCiudad* _tmp15_ = NULL;
		AumbralesBaseCiudad* _tmp50_ = NULL;
		AumbralesBaseCiudad* _tmp51_ = NULL;
		_tmp13_ = self->priv->stmt;
		_tmp14_ = sqlite3_step (_tmp13_);
		if (!(_tmp14_ == SQLITE_ROW)) {
			break;
		}
		_tmp15_ = aumbrales_base_ciudad_new ();
		c = _tmp15_;
		{
			gint i = 0;
			i = 0;
			{
				gboolean _tmp16_ = FALSE;
				_tmp16_ = TRUE;
				while (TRUE) {
					gint _tmp18_ = 0;
					gint _tmp19_ = 0;
					const gchar* _tmp20_ = NULL;
					sqlite3_stmt* _tmp21_ = NULL;
					gint _tmp22_ = 0;
					const gchar* _tmp23_ = NULL;
					gchar* col_name = NULL;
					gchar* _tmp24_ = NULL;
					const gchar* _tmp25_ = NULL;
					sqlite3_stmt* _tmp26_ = NULL;
					gint _tmp27_ = 0;
					const gchar* _tmp28_ = NULL;
					gchar* val = NULL;
					gchar* _tmp29_ = NULL;
					const gchar* _tmp30_ = NULL;
					const gchar* _tmp31_ = NULL;
					GQuark _tmp33_ = 0U;
					static GQuark _tmp32_label0 = 0;
					static GQuark _tmp32_label1 = 0;
					static GQuark _tmp32_label2 = 0;
					static GQuark _tmp32_label3 = 0;
					static GQuark _tmp32_label4 = 0;
					static GQuark _tmp32_label5 = 0;
					if (!_tmp16_) {
						gint _tmp17_ = 0;
						_tmp17_ = i;
						i = _tmp17_ + 1;
					}
					_tmp16_ = FALSE;
					_tmp18_ = i;
					_tmp19_ = cols;
					if (!(_tmp18_ < _tmp19_)) {
						break;
					}
					_tmp21_ = self->priv->stmt;
					_tmp22_ = i;
					_tmp23_ = sqlite3_column_name (_tmp21_, _tmp22_);
					_tmp20_ = _tmp23_;
					if (_tmp20_ == NULL) {
						_tmp20_ = "<none>";
					}
					_tmp24_ = g_strdup (_tmp20_);
					col_name = _tmp24_;
					_tmp26_ = self->priv->stmt;
					_tmp27_ = i;
					_tmp28_ = sqlite3_column_text (_tmp26_, _tmp27_);
					_tmp25_ = _tmp28_;
					if (_tmp25_ == NULL) {
						_tmp25_ = "<none>";
					}
					_tmp29_ = g_strdup (_tmp25_);
					val = _tmp29_;
					_tmp30_ = col_name;
					_tmp31_ = _tmp30_;
					_tmp33_ = (NULL == _tmp31_) ? 0 : g_quark_from_string (_tmp31_);
					if (_tmp33_ == ((0 != _tmp32_label0) ? _tmp32_label0 : (_tmp32_label0 = g_quark_from_static_string ("id")))) {
						switch (0) {
							default:
							{
								AumbralesBaseCiudad* _tmp34_ = NULL;
								const gchar* _tmp35_ = NULL;
								gint _tmp36_ = 0;
								_tmp34_ = c;
								_tmp35_ = val;
								_tmp36_ = atoi (_tmp35_);
								aumbrales_base_ciudad_set_id (_tmp34_, _tmp36_);
								break;
							}
						}
					} else if (_tmp33_ == ((0 != _tmp32_label1) ? _tmp32_label1 : (_tmp32_label1 = g_quark_from_static_string ("name")))) {
						switch (0) {
							default:
							{
								AumbralesBaseCiudad* _tmp37_ = NULL;
								const gchar* _tmp38_ = NULL;
								_tmp37_ = c;
								_tmp38_ = val;
								aumbrales_base_ciudad_set_nombre (_tmp37_, _tmp38_);
								break;
							}
						}
					} else if (_tmp33_ == ((0 != _tmp32_label2) ? _tmp32_label2 : (_tmp32_label2 = g_quark_from_static_string ("country")))) {
						switch (0) {
							default:
							{
								AumbralesBaseCiudad* _tmp39_ = NULL;
								const gchar* _tmp40_ = NULL;
								_tmp39_ = c;
								_tmp40_ = val;
								aumbrales_base_ciudad_set_pais (_tmp39_, _tmp40_);
								break;
							}
						}
					} else if (_tmp33_ == ((0 != _tmp32_label3) ? _tmp32_label3 : (_tmp32_label3 = g_quark_from_static_string ("population")))) {
						switch (0) {
							default:
							{
								AumbralesBaseCiudad* _tmp41_ = NULL;
								const gchar* _tmp42_ = NULL;
								gint _tmp43_ = 0;
								_tmp41_ = c;
								_tmp42_ = val;
								_tmp43_ = atoi (_tmp42_);
								aumbrales_base_ciudad_set_poblacion (_tmp41_, _tmp43_);
								break;
							}
						}
					} else if (_tmp33_ == ((0 != _tmp32_label4) ? _tmp32_label4 : (_tmp32_label4 = g_quark_from_static_string ("latitude")))) {
						switch (0) {
							default:
							{
								AumbralesBaseCiudad* _tmp44_ = NULL;
								const gchar* _tmp45_ = NULL;
								gdouble _tmp46_ = 0.0;
								_tmp44_ = c;
								_tmp45_ = val;
								_tmp46_ = double_parse (_tmp45_);
								aumbrales_base_ciudad_set_latitud (_tmp44_, _tmp46_);
								break;
							}
						}
					} else if (_tmp33_ == ((0 != _tmp32_label5) ? _tmp32_label5 : (_tmp32_label5 = g_quark_from_static_string ("longitude")))) {
						switch (0) {
							default:
							{
								AumbralesBaseCiudad* _tmp47_ = NULL;
								const gchar* _tmp48_ = NULL;
								gdouble _tmp49_ = 0.0;
								_tmp47_ = c;
								_tmp48_ = val;
								_tmp49_ = double_parse (_tmp48_);
								aumbrales_base_ciudad_set_longitud (_tmp47_, _tmp49_);
								break;
							}
						}
					}
					_g_free0 (val);
					_g_free0 (col_name);
				}
			}
		}
		_tmp50_ = c;
		_tmp51_ = _g_object_ref0 (_tmp50_);
		ci = g_list_append (ci, _tmp51_);
		_g_object_unref0 (c);
	}
	_tmp52_ = self->priv->stmt;
	sqlite3_reset (_tmp52_);
	result = ci;
	return result;
}


AumbralesBaseCiudad* aumbrales_modelo_db_getCiudad (AumbralesModeloDB* self, gint id) {
	AumbralesBaseCiudad* result = NULL;
	AumbralesBaseCiudad* c = NULL;
	AumbralesBaseCiudad* _tmp0_ = NULL;
	static const char prepared_query_str[] = "SELECT * FROM cities WHERE id =$UID;";
	gint ec = 0;
	sqlite3* _tmp1_ = NULL;
	gint _tmp2_ = 0;
	gint _tmp3_ = 0;
	sqlite3_stmt* _tmp4_ = NULL;
	gint _tmp5_ = 0;
	gint _tmp6_ = 0;
	gint param_position = 0;
	sqlite3_stmt* _tmp12_ = NULL;
	gint _tmp13_ = 0;
	gint _tmp14_ = 0;
	sqlite3_stmt* _tmp15_ = NULL;
	gint _tmp16_ = 0;
	gint _tmp17_ = 0;
	gint cols = 0;
	sqlite3_stmt* _tmp18_ = NULL;
	gint _tmp19_ = 0;
	sqlite3_stmt* _tmp56_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = aumbrales_base_ciudad_new ();
	c = _tmp0_;
	_tmp1_ = self->priv->db;
	_tmp2_ = strlen (prepared_query_str);
	_tmp3_ = _tmp2_;
	_tmp5_ = sqlite3_prepare_v2 (_tmp1_, prepared_query_str, _tmp3_, &_tmp4_, NULL);
	_sqlite3_finalize0 (self->priv->stmt);
	self->priv->stmt = _tmp4_;
	ec = _tmp5_;
	_tmp6_ = ec;
	if (_tmp6_ != SQLITE_OK) {
		FILE* _tmp7_ = NULL;
		sqlite3* _tmp8_ = NULL;
		gint _tmp9_ = 0;
		sqlite3* _tmp10_ = NULL;
		const gchar* _tmp11_ = NULL;
		_tmp7_ = stderr;
		_tmp8_ = self->priv->db;
		_tmp9_ = sqlite3_errcode (_tmp8_);
		_tmp10_ = self->priv->db;
		_tmp11_ = sqlite3_errmsg (_tmp10_);
		fprintf (_tmp7_, "Error: %d: %s\n", _tmp9_, _tmp11_);
	}
	_tmp12_ = self->priv->stmt;
	_tmp13_ = sqlite3_bind_parameter_index (_tmp12_, "$UID");
	param_position = _tmp13_;
	_tmp14_ = param_position;
	_vala_assert (_tmp14_ > 0, "param_position > 0");
	_tmp15_ = self->priv->stmt;
	_tmp16_ = param_position;
	_tmp17_ = id;
	sqlite3_bind_int (_tmp15_, _tmp16_, _tmp17_);
	_tmp18_ = self->priv->stmt;
	_tmp19_ = sqlite3_column_count (_tmp18_);
	cols = _tmp19_;
	while (TRUE) {
		sqlite3_stmt* _tmp20_ = NULL;
		gint _tmp21_ = 0;
		_tmp20_ = self->priv->stmt;
		_tmp21_ = sqlite3_step (_tmp20_);
		if (!(_tmp21_ == SQLITE_ROW)) {
			break;
		}
		{
			gint i = 0;
			i = 0;
			{
				gboolean _tmp22_ = FALSE;
				_tmp22_ = TRUE;
				while (TRUE) {
					gint _tmp24_ = 0;
					gint _tmp25_ = 0;
					const gchar* _tmp26_ = NULL;
					sqlite3_stmt* _tmp27_ = NULL;
					gint _tmp28_ = 0;
					const gchar* _tmp29_ = NULL;
					gchar* col_name = NULL;
					gchar* _tmp30_ = NULL;
					const gchar* _tmp31_ = NULL;
					sqlite3_stmt* _tmp32_ = NULL;
					gint _tmp33_ = 0;
					const gchar* _tmp34_ = NULL;
					gchar* val = NULL;
					gchar* _tmp35_ = NULL;
					const gchar* _tmp36_ = NULL;
					const gchar* _tmp37_ = NULL;
					GQuark _tmp39_ = 0U;
					static GQuark _tmp38_label0 = 0;
					static GQuark _tmp38_label1 = 0;
					static GQuark _tmp38_label2 = 0;
					static GQuark _tmp38_label3 = 0;
					static GQuark _tmp38_label4 = 0;
					static GQuark _tmp38_label5 = 0;
					if (!_tmp22_) {
						gint _tmp23_ = 0;
						_tmp23_ = i;
						i = _tmp23_ + 1;
					}
					_tmp22_ = FALSE;
					_tmp24_ = i;
					_tmp25_ = cols;
					if (!(_tmp24_ < _tmp25_)) {
						break;
					}
					_tmp27_ = self->priv->stmt;
					_tmp28_ = i;
					_tmp29_ = sqlite3_column_name (_tmp27_, _tmp28_);
					_tmp26_ = _tmp29_;
					if (_tmp26_ == NULL) {
						_tmp26_ = "<none>";
					}
					_tmp30_ = g_strdup (_tmp26_);
					col_name = _tmp30_;
					_tmp32_ = self->priv->stmt;
					_tmp33_ = i;
					_tmp34_ = sqlite3_column_text (_tmp32_, _tmp33_);
					_tmp31_ = _tmp34_;
					if (_tmp31_ == NULL) {
						_tmp31_ = "<none>";
					}
					_tmp35_ = g_strdup (_tmp31_);
					val = _tmp35_;
					_tmp36_ = col_name;
					_tmp37_ = _tmp36_;
					_tmp39_ = (NULL == _tmp37_) ? 0 : g_quark_from_string (_tmp37_);
					if (_tmp39_ == ((0 != _tmp38_label0) ? _tmp38_label0 : (_tmp38_label0 = g_quark_from_static_string ("id")))) {
						switch (0) {
							default:
							{
								AumbralesBaseCiudad* _tmp40_ = NULL;
								const gchar* _tmp41_ = NULL;
								gint _tmp42_ = 0;
								_tmp40_ = c;
								_tmp41_ = val;
								_tmp42_ = atoi (_tmp41_);
								aumbrales_base_ciudad_set_id (_tmp40_, _tmp42_);
								break;
							}
						}
					} else if (_tmp39_ == ((0 != _tmp38_label1) ? _tmp38_label1 : (_tmp38_label1 = g_quark_from_static_string ("name")))) {
						switch (0) {
							default:
							{
								AumbralesBaseCiudad* _tmp43_ = NULL;
								const gchar* _tmp44_ = NULL;
								_tmp43_ = c;
								_tmp44_ = val;
								aumbrales_base_ciudad_set_nombre (_tmp43_, _tmp44_);
								break;
							}
						}
					} else if (_tmp39_ == ((0 != _tmp38_label2) ? _tmp38_label2 : (_tmp38_label2 = g_quark_from_static_string ("country")))) {
						switch (0) {
							default:
							{
								AumbralesBaseCiudad* _tmp45_ = NULL;
								const gchar* _tmp46_ = NULL;
								_tmp45_ = c;
								_tmp46_ = val;
								aumbrales_base_ciudad_set_pais (_tmp45_, _tmp46_);
								break;
							}
						}
					} else if (_tmp39_ == ((0 != _tmp38_label3) ? _tmp38_label3 : (_tmp38_label3 = g_quark_from_static_string ("population")))) {
						switch (0) {
							default:
							{
								AumbralesBaseCiudad* _tmp47_ = NULL;
								const gchar* _tmp48_ = NULL;
								gint _tmp49_ = 0;
								_tmp47_ = c;
								_tmp48_ = val;
								_tmp49_ = atoi (_tmp48_);
								aumbrales_base_ciudad_set_poblacion (_tmp47_, _tmp49_);
								break;
							}
						}
					} else if (_tmp39_ == ((0 != _tmp38_label4) ? _tmp38_label4 : (_tmp38_label4 = g_quark_from_static_string ("latitude")))) {
						switch (0) {
							default:
							{
								AumbralesBaseCiudad* _tmp50_ = NULL;
								const gchar* _tmp51_ = NULL;
								gdouble _tmp52_ = 0.0;
								_tmp50_ = c;
								_tmp51_ = val;
								_tmp52_ = double_parse (_tmp51_);
								aumbrales_base_ciudad_set_latitud (_tmp50_, _tmp52_);
								break;
							}
						}
					} else if (_tmp39_ == ((0 != _tmp38_label5) ? _tmp38_label5 : (_tmp38_label5 = g_quark_from_static_string ("longitude")))) {
						switch (0) {
							default:
							{
								AumbralesBaseCiudad* _tmp53_ = NULL;
								const gchar* _tmp54_ = NULL;
								gdouble _tmp55_ = 0.0;
								_tmp53_ = c;
								_tmp54_ = val;
								_tmp55_ = double_parse (_tmp54_);
								aumbrales_base_ciudad_set_longitud (_tmp53_, _tmp55_);
								break;
							}
						}
					}
					_g_free0 (val);
					_g_free0 (col_name);
				}
			}
		}
	}
	_tmp56_ = self->priv->stmt;
	sqlite3_reset (_tmp56_);
	result = c;
	return result;
}


static gdouble* _double_dup (gdouble* self) {
	gdouble* dup;
	dup = g_new0 (gdouble, 1);
	memcpy (dup, self, sizeof (gdouble));
	return dup;
}


GeeHashMap* aumbrales_modelo_db_getConexiones (AumbralesModeloDB* self) {
	GeeHashMap* result = NULL;
	GeeHashMap* map = NULL;
	GeeHashMap* _tmp0_ = NULL;
	static const char prepared_query_str[] = "SELECT * FROM connections;";
	gint ec = 0;
	sqlite3* _tmp1_ = NULL;
	gint _tmp2_ = 0;
	gint _tmp3_ = 0;
	sqlite3_stmt* _tmp4_ = NULL;
	gint _tmp5_ = 0;
	gint _tmp6_ = 0;
	gint cols = 0;
	sqlite3_stmt* _tmp12_ = NULL;
	gint _tmp13_ = 0;
	sqlite3_stmt* _tmp48_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = gee_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, (GDestroyNotify) g_free, G_TYPE_DOUBLE, (GBoxedCopyFunc) _double_dup, (GDestroyNotify) g_free, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	map = _tmp0_;
	_tmp1_ = self->priv->db;
	_tmp2_ = strlen (prepared_query_str);
	_tmp3_ = _tmp2_;
	_tmp5_ = sqlite3_prepare_v2 (_tmp1_, prepared_query_str, _tmp3_, &_tmp4_, NULL);
	_sqlite3_finalize0 (self->priv->stmt);
	self->priv->stmt = _tmp4_;
	ec = _tmp5_;
	_tmp6_ = ec;
	if (_tmp6_ != SQLITE_OK) {
		FILE* _tmp7_ = NULL;
		sqlite3* _tmp8_ = NULL;
		gint _tmp9_ = 0;
		sqlite3* _tmp10_ = NULL;
		const gchar* _tmp11_ = NULL;
		_tmp7_ = stderr;
		_tmp8_ = self->priv->db;
		_tmp9_ = sqlite3_errcode (_tmp8_);
		_tmp10_ = self->priv->db;
		_tmp11_ = sqlite3_errmsg (_tmp10_);
		fprintf (_tmp7_, "Error: %d: %s\n", _tmp9_, _tmp11_);
	}
	_tmp12_ = self->priv->stmt;
	_tmp13_ = sqlite3_column_count (_tmp12_);
	cols = _tmp13_;
	while (TRUE) {
		sqlite3_stmt* _tmp14_ = NULL;
		gint _tmp15_ = 0;
		gchar* key = NULL;
		gchar* _tmp16_ = NULL;
		_tmp14_ = self->priv->stmt;
		_tmp15_ = sqlite3_step (_tmp14_);
		if (!(_tmp15_ == SQLITE_ROW)) {
			break;
		}
		_tmp16_ = g_strdup ("");
		key = _tmp16_;
		{
			gint i = 0;
			i = 0;
			{
				gboolean _tmp17_ = FALSE;
				_tmp17_ = TRUE;
				while (TRUE) {
					gint _tmp19_ = 0;
					gint _tmp20_ = 0;
					const gchar* _tmp21_ = NULL;
					sqlite3_stmt* _tmp22_ = NULL;
					gint _tmp23_ = 0;
					const gchar* _tmp24_ = NULL;
					gchar* col_name = NULL;
					gchar* _tmp25_ = NULL;
					const gchar* _tmp26_ = NULL;
					sqlite3_stmt* _tmp27_ = NULL;
					gint _tmp28_ = 0;
					const gchar* _tmp29_ = NULL;
					gchar* val = NULL;
					gchar* _tmp30_ = NULL;
					const gchar* _tmp31_ = NULL;
					const gchar* _tmp32_ = NULL;
					GQuark _tmp34_ = 0U;
					static GQuark _tmp33_label0 = 0;
					static GQuark _tmp33_label1 = 0;
					static GQuark _tmp33_label2 = 0;
					if (!_tmp17_) {
						gint _tmp18_ = 0;
						_tmp18_ = i;
						i = _tmp18_ + 1;
					}
					_tmp17_ = FALSE;
					_tmp19_ = i;
					_tmp20_ = cols;
					if (!(_tmp19_ < _tmp20_)) {
						break;
					}
					_tmp22_ = self->priv->stmt;
					_tmp23_ = i;
					_tmp24_ = sqlite3_column_name (_tmp22_, _tmp23_);
					_tmp21_ = _tmp24_;
					if (_tmp21_ == NULL) {
						_tmp21_ = "<none>";
					}
					_tmp25_ = g_strdup (_tmp21_);
					col_name = _tmp25_;
					_tmp27_ = self->priv->stmt;
					_tmp28_ = i;
					_tmp29_ = sqlite3_column_text (_tmp27_, _tmp28_);
					_tmp26_ = _tmp29_;
					if (_tmp26_ == NULL) {
						_tmp26_ = "<none>";
					}
					_tmp30_ = g_strdup (_tmp26_);
					val = _tmp30_;
					_tmp31_ = col_name;
					_tmp32_ = _tmp31_;
					_tmp34_ = (NULL == _tmp32_) ? 0 : g_quark_from_string (_tmp32_);
					if (_tmp34_ == ((0 != _tmp33_label0) ? _tmp33_label0 : (_tmp33_label0 = g_quark_from_static_string ("distance")))) {
						switch (0) {
							default:
							{
								gdouble d = 0.0;
								const gchar* _tmp35_ = NULL;
								gdouble _tmp36_ = 0.0;
								GeeHashMap* _tmp37_ = NULL;
								const gchar* _tmp38_ = NULL;
								gdouble _tmp39_ = 0.0;
								_tmp35_ = val;
								_tmp36_ = double_parse (_tmp35_);
								d = _tmp36_;
								_tmp37_ = map;
								_tmp38_ = key;
								_tmp39_ = d;
								gee_abstract_map_set ((GeeAbstractMap*) _tmp37_, _tmp38_, &_tmp39_);
								break;
							}
						}
					} else if (_tmp34_ == ((0 != _tmp33_label1) ? _tmp33_label1 : (_tmp33_label1 = g_quark_from_static_string ("id_city_1")))) {
						switch (0) {
							default:
							{
								const gchar* _tmp40_ = NULL;
								const gchar* _tmp41_ = NULL;
								gchar* _tmp42_ = NULL;
								gchar* _tmp43_ = NULL;
								gchar* _tmp44_ = NULL;
								_tmp40_ = key;
								_tmp41_ = val;
								_tmp42_ = g_strconcat (_tmp41_, ",", NULL);
								_tmp43_ = _tmp42_;
								_tmp44_ = g_strconcat (_tmp40_, _tmp43_, NULL);
								_g_free0 (key);
								key = _tmp44_;
								_g_free0 (_tmp43_);
								break;
							}
						}
					} else if (_tmp34_ == ((0 != _tmp33_label2) ? _tmp33_label2 : (_tmp33_label2 = g_quark_from_static_string ("id_city_2")))) {
						switch (0) {
							default:
							{
								const gchar* _tmp45_ = NULL;
								const gchar* _tmp46_ = NULL;
								gchar* _tmp47_ = NULL;
								_tmp45_ = key;
								_tmp46_ = val;
								_tmp47_ = g_strconcat (_tmp45_, _tmp46_, NULL);
								_g_free0 (key);
								key = _tmp47_;
								break;
							}
						}
					}
					_g_free0 (val);
					_g_free0 (col_name);
				}
			}
		}
		_g_free0 (key);
	}
	_tmp48_ = self->priv->stmt;
	sqlite3_reset (_tmp48_);
	result = map;
	return result;
}


static void aumbrales_modelo_db_class_init (AumbralesModeloDBClass * klass) {
	aumbrales_modelo_db_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (AumbralesModeloDBPrivate));
	G_OBJECT_CLASS (klass)->finalize = aumbrales_modelo_db_finalize;
}


static void aumbrales_modelo_db_instance_init (AumbralesModeloDB * self) {
	self->priv = AUMBRALES_MODELO_DB_GET_PRIVATE (self);
}


static void aumbrales_modelo_db_finalize (GObject* obj) {
	AumbralesModeloDB * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, AUMBRALES_TYPE_MODELO_DB, AumbralesModeloDB);
	_sqlite3_close0 (self->priv->db);
	_sqlite3_finalize0 (self->priv->stmt);
	G_OBJECT_CLASS (aumbrales_modelo_db_parent_class)->finalize (obj);
}


GType aumbrales_modelo_db_get_type (void) {
	static volatile gsize aumbrales_modelo_db_type_id__volatile = 0;
	if (g_once_init_enter (&aumbrales_modelo_db_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (AumbralesModeloDBClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) aumbrales_modelo_db_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (AumbralesModeloDB), 0, (GInstanceInitFunc) aumbrales_modelo_db_instance_init, NULL };
		GType aumbrales_modelo_db_type_id;
		aumbrales_modelo_db_type_id = g_type_register_static (G_TYPE_OBJECT, "AumbralesModeloDB", &g_define_type_info, 0);
		g_once_init_leave (&aumbrales_modelo_db_type_id__volatile, aumbrales_modelo_db_type_id);
	}
	return aumbrales_modelo_db_type_id__volatile;
}


