/***************************************************************************
 * ROM Properties Page shell extension. (GTK+ common)                      *
 * glib-compat.h: GLib compatibility functions.                            *
 *                                                                         *
 * Copyright (c) 2017-2022 by David Korth.                                 *
 * SPDX-License-Identifier: GPL-2.0-or-later                               *
 ***************************************************************************/

#ifndef __ROMPROPERTIES_GTK_GLIB_COMPAT_H__
#define __ROMPROPERTIES_GTK_GLIB_COMPAT_H__

#include <glib.h>

G_BEGIN_DECLS

/** Functions added in GLib 2.44.0 **/

// NOTE: g_autoptr was also added in 2.44.0.
// Not including g_autoptr functionality here.
#if !GLIB_CHECK_VERSION(2,43,4)
#define G_DECLARE_FINAL_TYPE(ModuleObjName, module_obj_name, MODULE, OBJ_NAME, ParentName) \
  GType module_obj_name##_get_type (void);                                                               \
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS                                                                       \
  typedef struct _##ModuleObjName ModuleObjName;                                                         \
  typedef struct { ParentName##Class parent_class; } ModuleObjName##Class;                               \
                                                                                                         \
  G_GNUC_UNUSED static inline ModuleObjName * MODULE##_##OBJ_NAME (gpointer ptr) {                       \
    return G_TYPE_CHECK_INSTANCE_CAST (ptr, module_obj_name##_get_type (), ModuleObjName); }             \
  G_GNUC_UNUSED static inline gboolean MODULE##_IS_##OBJ_NAME (gpointer ptr) {                           \
    return G_TYPE_CHECK_INSTANCE_TYPE (ptr, module_obj_name##_get_type ()); }                            \
  G_GNUC_END_IGNORE_DEPRECATIONS

#define G_DECLARE_INTERFACE(ModuleObjName, module_obj_name, MODULE, OBJ_NAME, PrerequisiteName) \
  GType module_obj_name##_get_type (void);                                                                 \
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS                                                                         \
  typedef struct _##ModuleObjName ModuleObjName;                                                           \
  typedef struct _##ModuleObjName##Interface ModuleObjName##Interface;                                     \
                                                                                                           \
  G_GNUC_UNUSED static inline ModuleObjName * MODULE##_##OBJ_NAME (gpointer ptr) {                         \
    return G_TYPE_CHECK_INSTANCE_CAST (ptr, module_obj_name##_get_type (), ModuleObjName); }               \
  G_GNUC_UNUSED static inline gboolean MODULE##_IS_##OBJ_NAME (gpointer ptr) {                             \
    return G_TYPE_CHECK_INSTANCE_TYPE (ptr, module_obj_name##_get_type ()); }                              \
  G_GNUC_UNUSED static inline ModuleObjName##Interface * MODULE##_##OBJ_NAME##_GET_IFACE (gpointer ptr) {  \
    return G_TYPE_INSTANCE_GET_INTERFACE (ptr, module_obj_name##_get_type (), ModuleObjName##Interface); } \
  G_GNUC_END_IGNORE_DEPRECATIONS
#endif /* !GLIB_CHECK_VERSION(2,43,4) */

/** Functions added in GLib 2.56.0 **/

#if !GLIB_CHECK_VERSION(2,55,0)
typedef void (* GClearHandleFunc) (guint handle_id);
#endif /* !GLIB_CHECK_VERSION(2,55,0) */

// NOTE: Always defining g_clear_handle_id() here to prevent
// warnings because we have a minimum GLib version set for warnings.
#ifdef g_clear_handle_id
#  undef g_clear_handle_id
#endif
#define g_clear_handle_id(tag_ptr, clear_func)             \
  G_STMT_START {                                           \
    G_STATIC_ASSERT (sizeof *(tag_ptr) == sizeof (guint)); \
    guint *_tag_ptr = (guint *) (tag_ptr);                 \
    guint _handle_id;                                      \
                                                           \
    _handle_id = *_tag_ptr;                                \
    if (_handle_id > 0)                                    \
      {                                                    \
        *_tag_ptr = 0;                                     \
        clear_func (_handle_id);                           \
      }                                                    \
  } G_STMT_END

G_END_DECLS

#endif /* __ROMPROPERTIES_GTK_GLIB_COMPAT_H__ */
