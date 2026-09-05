#pragma once

#include "labgl/gl.h"
#include "labgl/labgl_buffer.h"
#include "labgl/labgl_capture.h"
#include "labgl/labgl_window.h"

namespace gl {}
namespace labgl {}

namespace lgl_typed_detail {
  constexpr GLenum FLOAT = GL_FLOAT;
  constexpr GLenum FLOAT_MAT4 = GL_FLOAT_MAT4;
  constexpr GLenum INT = GL_INT;
  constexpr GLenum UNSIGNED_BYTE = GL_UNSIGNED_BYTE;
  constexpr GLenum UNSIGNED_INT = GL_UNSIGNED_INT;
  constexpr GLenum SAMPLER_2D = GL_SAMPLER_2D;
  constexpr GLenum CULL_FACE = GL_CULL_FACE;
  constexpr GLenum DEPTH_TEST = GL_DEPTH_TEST;
  constexpr GLenum LESS = GL_LESS;
  constexpr GLenum BACK = GL_BACK;
  constexpr GLenum CCW = GL_CCW;
  constexpr GLenum MODELVIEW = GL_MODELVIEW;
  constexpr GLenum PROJECTION = GL_PROJECTION;
  constexpr GLenum TRIANGLES = GL_TRIANGLES;
  constexpr GLenum VERTEX_ARRAY = GL_VERTEX_ARRAY;
  constexpr GLenum COLOR_ARRAY = GL_COLOR_ARRAY;
  constexpr GLenum NORMAL_ARRAY = GL_NORMAL_ARRAY;
  constexpr GLenum TEXTURE_COORD_ARRAY = GL_TEXTURE_COORD_ARRAY;
  constexpr GLenum ARRAY_BUFFER = GL_ARRAY_BUFFER;
  constexpr GLenum ELEMENT_ARRAY_BUFFER = GL_ELEMENT_ARRAY_BUFFER;
  constexpr GLenum TEXTURE_2D = GL_TEXTURE_2D;
  constexpr GLenum TEXTURE_MIN_FILTER = GL_TEXTURE_MIN_FILTER;
  constexpr GLenum TEXTURE_MAG_FILTER = GL_TEXTURE_MAG_FILTER;
  constexpr GLenum TEXTURE_WRAP_S = GL_TEXTURE_WRAP_S;
  constexpr GLenum TEXTURE_WRAP_T = GL_TEXTURE_WRAP_T;
  constexpr GLenum TEXTURE_MAX_LEVEL = GL_TEXTURE_MAX_LEVEL;
  constexpr GLenum TONEMAP_AGX = GL_TONEMAP_AGX;
  constexpr GLenum TONEMAP_ACES = GL_TONEMAP_ACES;
  constexpr GLenum TONEMAP_ACES_NARKOWICZ = GL_TONEMAP_ACES_NARKOWICZ;
  constexpr GLenum TONEMAP_KHRONOS_NEUTRAL = GL_TONEMAP_KHRONOS_NEUTRAL;
  constexpr GLenum TONEMAP_ACES_GUY = GL_TONEMAP_ACES_GUY;
  constexpr GLenum TONEMAP_ACES_HILL = GL_TONEMAP_ACES_HILL;
  constexpr GLenum TONEMAP_ALDRIDGE = GL_TONEMAP_ALDRIDGE;
  constexpr GLenum TONEMAP_CLAMPING = GL_TONEMAP_CLAMPING;
  constexpr GLenum TONEMAP_DAY = GL_TONEMAP_DAY;
  constexpr GLenum TONEMAP_DRAGO = GL_TONEMAP_DRAGO;
  constexpr GLenum TONEMAP_DURAND_DORSEY = GL_TONEMAP_DURAND_DORSEY;
  constexpr GLenum TONEMAP_EXPONENTIAL = GL_TONEMAP_EXPONENTIAL;
  constexpr GLenum TONEMAP_EXPONENTIATION = GL_TONEMAP_EXPONENTIATION;
  constexpr GLenum TONEMAP_FERWERDA = GL_TONEMAP_FERWERDA;
  constexpr GLenum TONEMAP_GAMMA = GL_TONEMAP_GAMMA;
  constexpr GLenum TONEMAP_HABLE = GL_TONEMAP_HABLE;
  constexpr GLenum TONEMAP_HABLE_UPDATED = GL_TONEMAP_HABLE_UPDATED;
  constexpr GLenum TONEMAP_HEJL_BURGESS_DAWSON = GL_TONEMAP_HEJL_BURGESS_DAWSON;
  constexpr GLenum TONEMAP_LOGARITHMIC = GL_TONEMAP_LOGARITHMIC;
  constexpr GLenum TONEMAP_LOTTES = GL_TONEMAP_LOTTES;
  constexpr GLenum TONEMAP_MAXDIVISION = GL_TONEMAP_MAXDIVISION;
  constexpr GLenum TONEMAP_MEANVALUE = GL_TONEMAP_MEANVALUE;
  constexpr GLenum TONEMAP_REINHARD = GL_TONEMAP_REINHARD;
  constexpr GLenum TONEMAP_REINHARD_DEVLIN = GL_TONEMAP_REINHARD_DEVLIN;
  constexpr GLenum TONEMAP_REINHARD_EXTENDED = GL_TONEMAP_REINHARD_EXTENDED;
  constexpr GLenum TONEMAP_SCHLICK = GL_TONEMAP_SCHLICK;
  constexpr GLenum TONEMAP_SRGB = GL_TONEMAP_SRGB;
  constexpr GLenum TONEMAP_TUMBLIN_RUSHMEIER = GL_TONEMAP_TUMBLIN_RUSHMEIER;
  constexpr GLenum TONEMAP_UCHIMURA = GL_TONEMAP_UCHIMURA;
  constexpr GLenum TONEMAP_WARD = GL_TONEMAP_WARD;
} // namespace lgl_typed_detail

#undef GL_FLOAT
#undef GL_FLOAT_MAT4
#undef GL_INT
#undef GL_UNSIGNED_BYTE
#undef GL_UNSIGNED_INT
#undef GL_SAMPLER_2D
#undef GL_CULL_FACE
#undef GL_DEPTH_TEST
#undef GL_LESS
#undef GL_BACK
#undef GL_CCW
#undef GL_MODELVIEW
#undef GL_PROJECTION
#undef GL_TRIANGLES
#undef GL_VERTEX_ARRAY
#undef GL_COLOR_ARRAY
#undef GL_NORMAL_ARRAY
#undef GL_TEXTURE_COORD_ARRAY
#undef GL_ARRAY_BUFFER
#undef GL_ELEMENT_ARRAY_BUFFER
#undef GL_TEXTURE_2D
#undef GL_TEXTURE_MIN_FILTER
#undef GL_TEXTURE_MAG_FILTER
#undef GL_TEXTURE_WRAP_S
#undef GL_TEXTURE_WRAP_T
#undef GL_TEXTURE_MAX_LEVEL
#undef GL_TONEMAP_AGX
#undef GL_TONEMAP_ACES
#undef GL_TONEMAP_ACES_NARKOWICZ
#undef GL_TONEMAP_KHRONOS_NEUTRAL
#undef GL_TONEMAP_ACES_GUY
#undef GL_TONEMAP_ACES_HILL
#undef GL_TONEMAP_ALDRIDGE
#undef GL_TONEMAP_CLAMPING
#undef GL_TONEMAP_DAY
#undef GL_TONEMAP_DRAGO
#undef GL_TONEMAP_DURAND_DORSEY
#undef GL_TONEMAP_EXPONENTIAL
#undef GL_TONEMAP_EXPONENTIATION
#undef GL_TONEMAP_FERWERDA
#undef GL_TONEMAP_GAMMA
#undef GL_TONEMAP_HABLE
#undef GL_TONEMAP_HABLE_UPDATED
#undef GL_TONEMAP_HEJL_BURGESS_DAWSON
#undef GL_TONEMAP_LOGARITHMIC
#undef GL_TONEMAP_LOTTES
#undef GL_TONEMAP_MAXDIVISION
#undef GL_TONEMAP_MEANVALUE
#undef GL_TONEMAP_REINHARD
#undef GL_TONEMAP_REINHARD_DEVLIN
#undef GL_TONEMAP_REINHARD_EXTENDED
#undef GL_TONEMAP_SCHLICK
#undef GL_TONEMAP_SRGB
#undef GL_TONEMAP_TUMBLIN_RUSHMEIER
#undef GL_TONEMAP_UCHIMURA
#undef GL_TONEMAP_WARD

constexpr GLenum GL_FLOAT = lgl_typed_detail::FLOAT;
constexpr GLenum GL_FLOAT_MAT4 = lgl_typed_detail::FLOAT_MAT4;
constexpr GLenum GL_INT = lgl_typed_detail::INT;
constexpr GLenum GL_UNSIGNED_BYTE = lgl_typed_detail::UNSIGNED_BYTE;
constexpr GLenum GL_UNSIGNED_INT = lgl_typed_detail::UNSIGNED_INT;
constexpr GLenum GL_SAMPLER_2D = lgl_typed_detail::SAMPLER_2D;
constexpr GLenum GL_CULL_FACE = lgl_typed_detail::CULL_FACE;
constexpr GLenum GL_DEPTH_TEST = lgl_typed_detail::DEPTH_TEST;
constexpr GLenum GL_LESS = lgl_typed_detail::LESS;
constexpr GLenum GL_BACK = lgl_typed_detail::BACK;
constexpr GLenum GL_CCW = lgl_typed_detail::CCW;
constexpr GLenum GL_MODELVIEW = lgl_typed_detail::MODELVIEW;
constexpr GLenum GL_PROJECTION = lgl_typed_detail::PROJECTION;
constexpr GLenum GL_TRIANGLES = lgl_typed_detail::TRIANGLES;
constexpr GLenum GL_VERTEX_ARRAY = lgl_typed_detail::VERTEX_ARRAY;
constexpr GLenum GL_COLOR_ARRAY = lgl_typed_detail::COLOR_ARRAY;
constexpr GLenum GL_NORMAL_ARRAY = lgl_typed_detail::NORMAL_ARRAY;
constexpr GLenum GL_TEXTURE_COORD_ARRAY = lgl_typed_detail::TEXTURE_COORD_ARRAY;
constexpr GLenum GL_ARRAY_BUFFER = lgl_typed_detail::ARRAY_BUFFER;
constexpr GLenum GL_ELEMENT_ARRAY_BUFFER = lgl_typed_detail::ELEMENT_ARRAY_BUFFER;
constexpr GLenum GL_TEXTURE_2D = lgl_typed_detail::TEXTURE_2D;
constexpr GLenum GL_TEXTURE_MIN_FILTER = lgl_typed_detail::TEXTURE_MIN_FILTER;
constexpr GLenum GL_TEXTURE_MAG_FILTER = lgl_typed_detail::TEXTURE_MAG_FILTER;
constexpr GLenum GL_TEXTURE_WRAP_S = lgl_typed_detail::TEXTURE_WRAP_S;
constexpr GLenum GL_TEXTURE_WRAP_T = lgl_typed_detail::TEXTURE_WRAP_T;
constexpr GLenum GL_TEXTURE_MAX_LEVEL = lgl_typed_detail::TEXTURE_MAX_LEVEL;
constexpr GLenum GL_TONEMAP_AGX = lgl_typed_detail::TONEMAP_AGX;
constexpr GLenum GL_TONEMAP_ACES = lgl_typed_detail::TONEMAP_ACES;
constexpr GLenum GL_TONEMAP_ACES_NARKOWICZ = lgl_typed_detail::TONEMAP_ACES_NARKOWICZ;
constexpr GLenum GL_TONEMAP_KHRONOS_NEUTRAL = lgl_typed_detail::TONEMAP_KHRONOS_NEUTRAL;
constexpr GLenum GL_TONEMAP_ACES_GUY = lgl_typed_detail::TONEMAP_ACES_GUY;
constexpr GLenum GL_TONEMAP_ACES_HILL = lgl_typed_detail::TONEMAP_ACES_HILL;
constexpr GLenum GL_TONEMAP_ALDRIDGE = lgl_typed_detail::TONEMAP_ALDRIDGE;
constexpr GLenum GL_TONEMAP_CLAMPING = lgl_typed_detail::TONEMAP_CLAMPING;
constexpr GLenum GL_TONEMAP_DAY = lgl_typed_detail::TONEMAP_DAY;
constexpr GLenum GL_TONEMAP_DRAGO = lgl_typed_detail::TONEMAP_DRAGO;
constexpr GLenum GL_TONEMAP_DURAND_DORSEY = lgl_typed_detail::TONEMAP_DURAND_DORSEY;
constexpr GLenum GL_TONEMAP_EXPONENTIAL = lgl_typed_detail::TONEMAP_EXPONENTIAL;
constexpr GLenum GL_TONEMAP_EXPONENTIATION = lgl_typed_detail::TONEMAP_EXPONENTIATION;
constexpr GLenum GL_TONEMAP_FERWERDA = lgl_typed_detail::TONEMAP_FERWERDA;
constexpr GLenum GL_TONEMAP_GAMMA = lgl_typed_detail::TONEMAP_GAMMA;
constexpr GLenum GL_TONEMAP_HABLE = lgl_typed_detail::TONEMAP_HABLE;
constexpr GLenum GL_TONEMAP_HABLE_UPDATED = lgl_typed_detail::TONEMAP_HABLE_UPDATED;
constexpr GLenum GL_TONEMAP_HEJL_BURGESS_DAWSON = lgl_typed_detail::TONEMAP_HEJL_BURGESS_DAWSON;
constexpr GLenum GL_TONEMAP_LOGARITHMIC = lgl_typed_detail::TONEMAP_LOGARITHMIC;
constexpr GLenum GL_TONEMAP_LOTTES = lgl_typed_detail::TONEMAP_LOTTES;
constexpr GLenum GL_TONEMAP_MAXDIVISION = lgl_typed_detail::TONEMAP_MAXDIVISION;
constexpr GLenum GL_TONEMAP_MEANVALUE = lgl_typed_detail::TONEMAP_MEANVALUE;
constexpr GLenum GL_TONEMAP_REINHARD = lgl_typed_detail::TONEMAP_REINHARD;
constexpr GLenum GL_TONEMAP_REINHARD_DEVLIN = lgl_typed_detail::TONEMAP_REINHARD_DEVLIN;
constexpr GLenum GL_TONEMAP_REINHARD_EXTENDED = lgl_typed_detail::TONEMAP_REINHARD_EXTENDED;
constexpr GLenum GL_TONEMAP_SCHLICK = lgl_typed_detail::TONEMAP_SCHLICK;
constexpr GLenum GL_TONEMAP_SRGB = lgl_typed_detail::TONEMAP_SRGB;
constexpr GLenum GL_TONEMAP_TUMBLIN_RUSHMEIER = lgl_typed_detail::TONEMAP_TUMBLIN_RUSHMEIER;
constexpr GLenum GL_TONEMAP_UCHIMURA = lgl_typed_detail::TONEMAP_UCHIMURA;
constexpr GLenum GL_TONEMAP_WARD = lgl_typed_detail::TONEMAP_WARD;
