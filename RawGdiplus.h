/**************************************************************************\
*
* Copyright (c) 1998-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   RawGdiplus.h
*
* Abstract:
*
*   Raw GDI+ C/C++ header file
*
\**************************************************************************/

#ifndef _RAWGDIPLUS_H
#define _RAWGDIPLUS_H

#pragma once

struct IDirectDrawSurface7;

typedef signed   short   INT16;
typedef unsigned short  UINT16;


// Define the Current GDIPlus Version
#ifndef GDIPVER
#define GDIPVER 0x0100
#endif

#include <pshpack8.h>   // set structure packing to 8

#ifdef __cplusplus
extern "C" {
#endif

#define WINGDIPAPI __stdcall
#define GDIPCONST const

//----------------------------------------------------------------------------
// Memory Allocation APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT void* WINGDIPAPI
GdipAlloc(size_t size);

DECLSPEC_IMPORT void WINGDIPAPI
GdipFree(void* ptr);

//--------------------------------------------------------------------------
// Default bezier flattening tolerance in device pixels.
//--------------------------------------------------------------------------

const float GpFlatnessDefault = 1.0f/4.0f;

//--------------------------------------------------------------------------
// Graphics and Container State cookies
//--------------------------------------------------------------------------

typedef UINT     GpGraphicsState;
typedef UINT     GpGraphicsContainer;

//--------------------------------------------------------------------------
// Fill mode constants
//--------------------------------------------------------------------------

typedef enum GpFillMode
{
    GpFillModeAlternate,        // 0
    GpFillModeWinding           // 1
} GpFillMode;

//--------------------------------------------------------------------------
// Quality mode constants
//--------------------------------------------------------------------------

typedef enum GpQualityMode
{
    GpQualityModeInvalid   = -1,
    GpQualityModeDefault   = 0,
    GpQualityModeLow       = 1, // Best performance
    GpQualityModeHigh      = 2  // Best rendering quality
} GpQualityMode;

//--------------------------------------------------------------------------
// Alpha Compositing mode constants
//--------------------------------------------------------------------------

typedef enum GpCompositingMode
{
    GpCompositingModeSourceOver,    // 0
    GpCompositingModeSourceCopy     // 1
} GpCompositingMode;

//--------------------------------------------------------------------------
// Alpha Compositing quality constants
//--------------------------------------------------------------------------

typedef enum GpCompositingQuality
{
    GpCompositingQualityInvalid          = GpQualityModeInvalid,
    GpCompositingQualityDefault          = GpQualityModeDefault,
    GpCompositingQualityHighSpeed        = GpQualityModeLow,
    GpCompositingQualityHighQuality      = GpQualityModeHigh,
    GpCompositingQualityGammaCorrected,
    GpCompositingQualityAssumeLinear
} GpCompositingQuality;

//--------------------------------------------------------------------------
// Unit constants
//--------------------------------------------------------------------------

typedef enum GpUnit
{
    GpUnitWorld,      // 0 -- World coordinate (non-physical unit)
    GpUnitDisplay,    // 1 -- Variable -- for PageTransform only
    GpUnitPixel,      // 2 -- Each unit is one device pixel.
    GpUnitPoint,      // 3 -- Each unit is a printer's point, or 1/72 inch.
    GpUnitInch,       // 4 -- Each unit is 1 inch.
    GpUnitDocument,   // 5 -- Each unit is 1/300 inch.
    GpUnitMillimeter  // 6 -- Each unit is 1 millimeter.
} GpUnit;

//--------------------------------------------------------------------------
// MetafileFrameUnit
//
// The frameRect for creating a metafile can be specified in any of these
// units.  There is an extra frame unit value (MetafileFrameUnitGdi) so
// that units can be supplied in the same units that GDI expects for
// frame rects -- these units are in .01 (1/100ths) millimeter units
// as defined by GDI.
//--------------------------------------------------------------------------

typedef enum GpMetafileFrameUnit
{
    GpMetafileFrameUnitPixel      = GpUnitPixel,
    GpMetafileFrameUnitPoint      = GpUnitPoint,
    GpMetafileFrameUnitInch       = GpUnitInch,
    GpMetafileFrameUnitDocument   = GpUnitDocument,
    GpMetafileFrameUnitMillimeter = GpUnitMillimeter,
    GpMetafileFrameUnitGdi                        // GDI compatible .01 MM units
} GpMetafileFrameUnit;

//--------------------------------------------------------------------------
// Coordinate space identifiers
//--------------------------------------------------------------------------

typedef enum GpCoordinateSpace
{
    GpCoordinateSpaceWorld,     // 0
    GpCoordinateSpacePage,      // 1
    GpCoordinateSpaceDevice     // 2
} GpCoordinateSpace;

//--------------------------------------------------------------------------
// Various wrap modes for brushes
//--------------------------------------------------------------------------

typedef enum GpWrapMode
{
    GpWrapModeTile,        // 0
    GpWrapModeTileFlipX,   // 1
    GpWrapModeTileFlipY,   // 2
    GpWrapModeTileFlipXY,  // 3
    GpWrapModeClamp        // 4
} GpWrapMode;

//--------------------------------------------------------------------------
// Various hatch styles
//--------------------------------------------------------------------------

typedef enum GpHatchStyle
{
    GpHatchStyleHorizontal,                   // 0
    GpHatchStyleVertical,                     // 1
    GpHatchStyleForwardDiagonal,              // 2
    GpHatchStyleBackwardDiagonal,             // 3
    GpHatchStyleCross,                        // 4
    GpHatchStyleDiagonalCross,                // 5
    GpHatchStyle05Percent,                    // 6
    GpHatchStyle10Percent,                    // 7
    GpHatchStyle20Percent,                    // 8
    GpHatchStyle25Percent,                    // 9
    GpHatchStyle30Percent,                    // 10
    GpHatchStyle40Percent,                    // 11
    GpHatchStyle50Percent,                    // 12
    GpHatchStyle60Percent,                    // 13
    GpHatchStyle70Percent,                    // 14
    GpHatchStyle75Percent,                    // 15
    GpHatchStyle80Percent,                    // 16
    GpHatchStyle90Percent,                    // 17
    GpHatchStyleLightDownwardDiagonal,        // 18
    GpHatchStyleLightUpwardDiagonal,          // 19
    GpHatchStyleDarkDownwardDiagonal,         // 20
    GpHatchStyleDarkUpwardDiagonal,           // 21
    GpHatchStyleWideDownwardDiagonal,         // 22
    GpHatchStyleWideUpwardDiagonal,           // 23
    GpHatchStyleLightVertical,                // 24
    GpHatchStyleLightHorizontal,              // 25
    GpHatchStyleNarrowVertical,               // 26
    GpHatchStyleNarrowHorizontal,             // 27
    GpHatchStyleDarkVertical,                 // 28
    GpHatchStyleDarkHorizontal,               // 29
    GpHatchStyleDashedDownwardDiagonal,       // 30
    GpHatchStyleDashedUpwardDiagonal,         // 31
    GpHatchStyleDashedHorizontal,             // 32
    GpHatchStyleDashedVertical,               // 33
    GpHatchStyleSmallConfetti,                // 34
    GpHatchStyleLargeConfetti,                // 35
    GpHatchStyleZigZag,                       // 36
    GpHatchStyleWave,                         // 37
    GpHatchStyleDiagonalBrick,                // 38
    GpHatchStyleHorizontalBrick,              // 39
    GpHatchStyleWeave,                        // 40
    GpHatchStylePlaid,                        // 41
    GpHatchStyleDivot,                        // 42
    GpHatchStyleDottedGrid,                   // 43
    GpHatchStyleDottedDiamond,                // 44
    GpHatchStyleShingle,                      // 45
    GpHatchStyleTrellis,                      // 46
    GpHatchStyleSphere,                       // 47
    GpHatchStyleSmallGrid,                    // 48
    GpHatchStyleSmallCheckerBoard,            // 49
    GpHatchStyleLargeCheckerBoard,            // 50
    GpHatchStyleOutlinedDiamond,              // 51
    GpHatchStyleSolidDiamond,                 // 52

    GpHatchStyleTotal,   
    GpHatchStyleLargeGrid = GpHatchStyleCross,  // 4

    GpHatchStyleMin       = GpHatchStyleHorizontal,
    GpHatchStyleMax       = GpHatchStyleTotal - 1,
} GpHatchStyle;

//--------------------------------------------------------------------------
// Dash style constants
//--------------------------------------------------------------------------

typedef enum GpDashStyle
{
    GpDashStyleSolid,          // 0
    GpDashStyleDash,           // 1
    GpDashStyleDot,            // 2
    GpDashStyleDashDot,        // 3
    GpDashStyleDashDotDot,     // 4
    GpDashStyleCustom          // 5
} GpDashStyle;

//--------------------------------------------------------------------------
// Dash cap constants
//--------------------------------------------------------------------------

typedef enum GpDashCap
{
    GpDashCapFlat             = 0,
    GpDashCapRound            = 2,
    GpDashCapTriangle         = 3
} GpDashCap;

//--------------------------------------------------------------------------
// Line cap constants (only the lowest 8 bits are used).
//--------------------------------------------------------------------------

typedef enum GpLineCap
{
    GpLineCapFlat             = 0,
    GpLineCapSquare           = 1,
    GpLineCapRound            = 2,
    GpLineCapTriangle         = 3,

    GpLineCapNoAnchor         = 0x10, // corresponds to flat cap
    GpLineCapSquareAnchor     = 0x11, // corresponds to square cap
    GpLineCapRoundAnchor      = 0x12, // corresponds to round cap
    GpLineCapDiamondAnchor    = 0x13, // corresponds to triangle cap
    GpLineCapArrowAnchor      = 0x14, // no correspondence

    GpLineCapCustom           = 0xff, // custom cap

    GpLineCapAnchorMask       = 0xf0  // mask to check for anchor or not.
} GpLineCap;

//--------------------------------------------------------------------------
// Custom Line cap type constants
//--------------------------------------------------------------------------

typedef enum GpCustomLineCapType
{
    GpCustomLineCapTypeDefault         = 0,
    GpCustomLineCapTypeAdjustableArrow = 1
} GpCustomLineCapType;

//--------------------------------------------------------------------------
// Line join constants
//--------------------------------------------------------------------------

typedef enum GpLineJoin
{
    GpLineJoinMiter        = 0,
    GpLineJoinBevel        = 1,
    GpLineJoinRound        = 2,
    GpLineJoinMiterClipped = 3
} GpLineJoin;

//--------------------------------------------------------------------------
// Path point types (only the lowest 8 bits are used.)
//  The lowest 3 bits are interpreted as point type
//  The higher 5 bits are reserved for flags.
//--------------------------------------------------------------------------

typedef enum GpPathPointType
{
    GpPathPointTypeStart           = 0,    // move
    GpPathPointTypeLine            = 1,    // line
    GpPathPointTypeBezier          = 3,    // default Bezier (= cubic Bezier)
    GpPathPointTypePathTypeMask    = 0x07, // type mask (lowest 3 bits).
    GpPathPointTypeDashMode        = 0x10, // currently in dash mode.
    GpPathPointTypePathMarker      = 0x20, // a marker for the path.
    GpPathPointTypeCloseSubpath    = 0x80, // closed flag

    // Path types used for advanced path.

    GpPathPointTypeBezier3    = 3,         // cubic Bezier
} GpPathPointType;


//--------------------------------------------------------------------------
// WarpMode constants
//--------------------------------------------------------------------------

typedef enum GpWarpMode
{
    GpWarpModePerspective,    // 0
    GpWarpModeBilinear        // 1
} GpWarpMode;

//--------------------------------------------------------------------------
// LineGradient Mode
//--------------------------------------------------------------------------

typedef enum GpLinearGradientMode
{
    GpLinearGradientModeHorizontal,         // 0
    GpLinearGradientModeVertical,           // 1
    GpLinearGradientModeForwardDiagonal,    // 2
    GpLinearGradientModeBackwardDiagonal    // 3
} GpLinearGradientMode;

//--------------------------------------------------------------------------
// Region Comine Modes
//--------------------------------------------------------------------------

typedef enum GpCombineMode
{
    GpCombineModeReplace,     // 0
    GpCombineModeIntersect,   // 1
    GpCombineModeUnion,       // 2
    GpCombineModeXor,         // 3
    GpCombineModeExclude,     // 4
    GpCombineModeComplement   // 5 (Exclude From)
} GpCombineMode;

//--------------------------------------------------------------------------
 // Image types
//--------------------------------------------------------------------------

typedef enum GpImageType
{
    GpImageTypeUnknown,   // 0
    GpImageTypeBitmap,    // 1
    GpImageTypeMetafile   // 2
} GpImageType;

//--------------------------------------------------------------------------
// Interpolation modes
//--------------------------------------------------------------------------

typedef enum GpInterpolationMode
{
    GpInterpolationModeInvalid          = GpQualityModeInvalid,
    GpInterpolationModeDefault          = GpQualityModeDefault,
    GpInterpolationModeLowQuality       = GpQualityModeLow,
    GpInterpolationModeHighQuality      = GpQualityModeHigh,
    GpInterpolationModeBilinear,
    GpInterpolationModeBicubic,
    GpInterpolationModeNearestNeighbor,
    GpInterpolationModeHighQualityBilinear,
    GpInterpolationModeHighQualityBicubic
} GpInterpolationMode;

//--------------------------------------------------------------------------
// Pen types
//--------------------------------------------------------------------------

typedef enum GpPenAlignment
{
    GpPenAlignmentCenter       = 0,
    GpPenAlignmentInset        = 1
} GpPenAlignment;

//--------------------------------------------------------------------------
// Brush types
//--------------------------------------------------------------------------

typedef enum GpBrushType
{
   GpBrushTypeSolidColor       = 0,
   GpBrushTypeHatchFill        = 1,
   GpBrushTypeTextureFill      = 2,
   GpBrushTypePathGradient     = 3,
   GpBrushTypeLinearGradient   = 4
} GpBrushType;

//--------------------------------------------------------------------------
// Pen's Fill types
//--------------------------------------------------------------------------

typedef enum GpPenType
{
   GpPenTypeSolidColor       = GpBrushTypeSolidColor,
   GpPenTypeHatchFill        = GpBrushTypeHatchFill,
   GpPenTypeTextureFill      = GpBrushTypeTextureFill,
   GpPenTypePathGradient     = GpBrushTypePathGradient,
   GpPenTypeLinearGradient   = GpBrushTypeLinearGradient,
   GpPenTypeUnknown          = -1
} GpPenType;

//--------------------------------------------------------------------------
// Matrix Order
//--------------------------------------------------------------------------

typedef enum GpMatrixOrder
{
    GpMatrixOrderPrepend    = 0,
    GpMatrixOrderAppend     = 1
} GpMatrixOrder;

//--------------------------------------------------------------------------
// Generic font families
//--------------------------------------------------------------------------

typedef enum GpGenericFontFamily
{
    GpGenericFontFamilySerif,
    GpGenericFontFamilySansSerif,
    GpGenericFontFamilyMonospace

} GpGenericFontFamily;

//--------------------------------------------------------------------------
// FontStyle: face types and common styles
//--------------------------------------------------------------------------

typedef enum GpFontStyle
{
    GpFontStyleRegular    = 0,
    GpFontStyleBold       = 1,
    GpFontStyleItalic     = 2,
    GpFontStyleBoldItalic = 3,
    GpFontStyleUnderline  = 4,
    GpFontStyleStrikeout  = 8
} GpFontStyle;

//---------------------------------------------------------------------------
// Smoothing Mode
//---------------------------------------------------------------------------

typedef enum GpSmoothingMode
{
    GpSmoothingModeInvalid     = GpQualityModeInvalid,
    GpSmoothingModeDefault     = GpQualityModeDefault,
    GpSmoothingModeHighSpeed   = GpQualityModeLow,
    GpSmoothingModeHighQuality = GpQualityModeHigh,
    GpSmoothingModeNone,
    GpSmoothingModeAntiAlias,
#if (GDIPVER >= 0x0110)
    GpSmoothingModeAntiAlias8x4 = GpSmoothingModeAntiAlias,
    GpSmoothingModeAntiAlias8x8
#endif //(GDIPVER >= 0x0110) 
} GpSmoothingMode;

//---------------------------------------------------------------------------
// Pixel Format Mode
//---------------------------------------------------------------------------

typedef enum GpPixelOffsetMode
{
    GpPixelOffsetModeInvalid     = GpQualityModeInvalid,
    GpPixelOffsetModeDefault     = GpQualityModeDefault,
    GpPixelOffsetModeHighSpeed   = GpQualityModeLow,
    GpPixelOffsetModeHighQuality = GpQualityModeHigh,
    GpPixelOffsetModeNone,    // No pixel offset
    GpPixelOffsetModeHalf     // Offset by -0.5, -0.5 for fast anti-alias perf
} GpPixelOffsetMode;

//---------------------------------------------------------------------------
// Text Rendering Hint
//---------------------------------------------------------------------------

typedef enum GpTextRenderingHint
{
    GpTextRenderingHintSystemDefault = 0,            // Glyph with system default rendering hint
    GpTextRenderingHintSingleBitPerPixelGridFit,     // Glyph bitmap with hinting
    GpTextRenderingHintSingleBitPerPixel,            // Glyph bitmap without hinting
    GpTextRenderingHintAntiAliasGridFit,             // Glyph anti-alias bitmap with hinting
    GpTextRenderingHintAntiAlias,                    // Glyph anti-alias bitmap without hinting
    GpTextRenderingHintClearTypeGridFit              // Glyph CT bitmap with hinting
} GpTextRenderingHint;

//---------------------------------------------------------------------------
// Metafile Types
//---------------------------------------------------------------------------

typedef enum GpMetafileType
{
    GpMetafileTypeInvalid,            // Invalid metafile
    GpMetafileTypeWmf,                // Standard WMF
    GpMetafileTypeWmfPlaceable,       // Placeable WMF
    GpMetafileTypeEmf,                // EMF (not EMF+)
    GpMetafileTypeEmfPlusOnly,        // EMF+ without dual, down-level records
    GpMetafileTypeEmfPlusDual         // EMF+ with dual, down-level records
} GpMetafileType;

//---------------------------------------------------------------------------
// Specifies the type of EMF to record
//---------------------------------------------------------------------------

typedef enum GpEmfType
{
    GpEmfTypeEmfOnly     = GpMetafileTypeEmf,          // no EMF+, only EMF
    GpEmfTypeEmfPlusOnly = GpMetafileTypeEmfPlusOnly,  // no EMF, only EMF+
    GpEmfTypeEmfPlusDual = GpMetafileTypeEmfPlusDual   // both EMF+ and EMF
} GpEmfType;

//---------------------------------------------------------------------------
// EMF+ Persistent object types
//---------------------------------------------------------------------------

typedef enum GpObjectType
{
    GpObjectTypeInvalid,
    GpObjectTypeBrush,
    GpObjectTypePen,
    GpObjectTypePath,
    GpObjectTypeRegion,
    GpObjectTypeImage,
    GpObjectTypeFont,
    GpObjectTypeStringFormat,
    GpObjectTypeImageAttributes,
    GpObjectTypeCustomLineCap,
#if (GDIPVER >= 0x0110)
    GpObjectTypeGraphics,

    GpObjectTypeMax = GpObjectTypeGraphics,
#else
    GpObjectTypeMax = GpObjectTypeCustomLineCap,
#endif //(GDIPVER >= 0x0110)
    GpObjectTypeMin = GpObjectTypeBrush
} GpObjectType;

//---------------------------------------------------------------------------
// EMF+ Records
//---------------------------------------------------------------------------

// We have to change the WMF record numbers so that they don't conflict with
// the EMF and EMF+ record numbers.

#define GDIP_EMFPLUS_RECORD_BASE        0x00004000
#define GDIP_WMF_RECORD_BASE            0x00010000
#define GDIP_WMF_RECORD_TO_EMFPLUS(n)   ((enum GpEmfPlusRecordType)((n) | GDIP_WMF_RECORD_BASE))
#define GDIP_EMFPLUS_RECORD_TO_WMF(n)   ((n) & (~GDIP_WMF_RECORD_BASE))
#define GDIP_IS_WMF_RECORDTYPE(n)       (((n) & GDIP_WMF_RECORD_BASE) != 0)

typedef enum GpEmfPlusRecordType
{
   // Since we have to enumerate GDI records right along with GDI+ records,
   // We list all the GDI records here so that they can be part of the
   // same enumeration type which is used in the enumeration callback.

    GpWmfRecordTypeSetBkColor              = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETBKCOLOR),
    GpWmfRecordTypeSetBkMode               = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETBKMODE),
    GpWmfRecordTypeSetMapMode              = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETMAPMODE),
    GpWmfRecordTypeSetROP2                 = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETROP2),
    GpWmfRecordTypeSetRelAbs               = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETRELABS),
    GpWmfRecordTypeSetPolyFillMode         = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETPOLYFILLMODE),
    GpWmfRecordTypeSetStretchBltMode       = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETSTRETCHBLTMODE),
    GpWmfRecordTypeSetTextCharExtra        = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETTEXTCHAREXTRA),
    GpWmfRecordTypeSetTextColor            = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETTEXTCOLOR),
    GpWmfRecordTypeSetTextJustification    = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETTEXTJUSTIFICATION),
    GpWmfRecordTypeSetWindowOrg            = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETWINDOWORG),
    GpWmfRecordTypeSetWindowExt            = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETWINDOWEXT),
    GpWmfRecordTypeSetViewportOrg          = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETVIEWPORTORG),
    GpWmfRecordTypeSetViewportExt          = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETVIEWPORTEXT),
    GpWmfRecordTypeOffsetWindowOrg         = GDIP_WMF_RECORD_TO_EMFPLUS(META_OFFSETWINDOWORG),
    GpWmfRecordTypeScaleWindowExt          = GDIP_WMF_RECORD_TO_EMFPLUS(META_SCALEWINDOWEXT),
    GpWmfRecordTypeOffsetViewportOrg       = GDIP_WMF_RECORD_TO_EMFPLUS(META_OFFSETVIEWPORTORG),
    GpWmfRecordTypeScaleViewportExt        = GDIP_WMF_RECORD_TO_EMFPLUS(META_SCALEVIEWPORTEXT),
    GpWmfRecordTypeLineTo                  = GDIP_WMF_RECORD_TO_EMFPLUS(META_LINETO),
    GpWmfRecordTypeMoveTo                  = GDIP_WMF_RECORD_TO_EMFPLUS(META_MOVETO),
    GpWmfRecordTypeExcludeClipRect         = GDIP_WMF_RECORD_TO_EMFPLUS(META_EXCLUDECLIPRECT),
    GpWmfRecordTypeIntersectClipRect       = GDIP_WMF_RECORD_TO_EMFPLUS(META_INTERSECTCLIPRECT),
    GpWmfRecordTypeArc                     = GDIP_WMF_RECORD_TO_EMFPLUS(META_ARC),
    GpWmfRecordTypeEllipse                 = GDIP_WMF_RECORD_TO_EMFPLUS(META_ELLIPSE),
    GpWmfRecordTypeFloodFill               = GDIP_WMF_RECORD_TO_EMFPLUS(META_FLOODFILL),
    GpWmfRecordTypePie                     = GDIP_WMF_RECORD_TO_EMFPLUS(META_PIE),
    GpWmfRecordTypeRectangle               = GDIP_WMF_RECORD_TO_EMFPLUS(META_RECTANGLE),
    GpWmfRecordTypeRoundRect               = GDIP_WMF_RECORD_TO_EMFPLUS(META_ROUNDRECT),
    GpWmfRecordTypePatBlt                  = GDIP_WMF_RECORD_TO_EMFPLUS(META_PATBLT),
    GpWmfRecordTypeSaveDC                  = GDIP_WMF_RECORD_TO_EMFPLUS(META_SAVEDC),
    GpWmfRecordTypeSetPixel                = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETPIXEL),
    GpWmfRecordTypeOffsetClipRgn           = GDIP_WMF_RECORD_TO_EMFPLUS(META_OFFSETCLIPRGN),
    GpWmfRecordTypeTextOut                 = GDIP_WMF_RECORD_TO_EMFPLUS(META_TEXTOUT),
    GpWmfRecordTypeBitBlt                  = GDIP_WMF_RECORD_TO_EMFPLUS(META_BITBLT),
    GpWmfRecordTypeStretchBlt              = GDIP_WMF_RECORD_TO_EMFPLUS(META_STRETCHBLT),
    GpWmfRecordTypePolygon                 = GDIP_WMF_RECORD_TO_EMFPLUS(META_POLYGON),
    GpWmfRecordTypePolyline                = GDIP_WMF_RECORD_TO_EMFPLUS(META_POLYLINE),
    GpWmfRecordTypeEscape                  = GDIP_WMF_RECORD_TO_EMFPLUS(META_ESCAPE),
    GpWmfRecordTypeRestoreDC               = GDIP_WMF_RECORD_TO_EMFPLUS(META_RESTOREDC),
    GpWmfRecordTypeFillRegion              = GDIP_WMF_RECORD_TO_EMFPLUS(META_FILLREGION),
    GpWmfRecordTypeFrameRegion             = GDIP_WMF_RECORD_TO_EMFPLUS(META_FRAMEREGION),
    GpWmfRecordTypeInvertRegion            = GDIP_WMF_RECORD_TO_EMFPLUS(META_INVERTREGION),
    GpWmfRecordTypePaintRegion             = GDIP_WMF_RECORD_TO_EMFPLUS(META_PAINTREGION),
    GpWmfRecordTypeSelectClipRegion        = GDIP_WMF_RECORD_TO_EMFPLUS(META_SELECTCLIPREGION),
    GpWmfRecordTypeSelectObject            = GDIP_WMF_RECORD_TO_EMFPLUS(META_SELECTOBJECT),
    GpWmfRecordTypeSetTextAlign            = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETTEXTALIGN),
    GpWmfRecordTypeDrawText                = GDIP_WMF_RECORD_TO_EMFPLUS(0x062F),  // META_DRAWTEXT
    GpWmfRecordTypeChord                   = GDIP_WMF_RECORD_TO_EMFPLUS(META_CHORD),
    GpWmfRecordTypeSetMapperFlags          = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETMAPPERFLAGS),
    GpWmfRecordTypeExtTextOut              = GDIP_WMF_RECORD_TO_EMFPLUS(META_EXTTEXTOUT),
    GpWmfRecordTypeSetDIBToDev             = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETDIBTODEV),
    GpWmfRecordTypeSelectPalette           = GDIP_WMF_RECORD_TO_EMFPLUS(META_SELECTPALETTE),
    GpWmfRecordTypeRealizePalette          = GDIP_WMF_RECORD_TO_EMFPLUS(META_REALIZEPALETTE),
    GpWmfRecordTypeAnimatePalette          = GDIP_WMF_RECORD_TO_EMFPLUS(META_ANIMATEPALETTE),
    GpWmfRecordTypeSetPalEntries           = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETPALENTRIES),
    GpWmfRecordTypePolyPolygon             = GDIP_WMF_RECORD_TO_EMFPLUS(META_POLYPOLYGON),
    GpWmfRecordTypeResizePalette           = GDIP_WMF_RECORD_TO_EMFPLUS(META_RESIZEPALETTE),
    GpWmfRecordTypeDIBBitBlt               = GDIP_WMF_RECORD_TO_EMFPLUS(META_DIBBITBLT),
    GpWmfRecordTypeDIBStretchBlt           = GDIP_WMF_RECORD_TO_EMFPLUS(META_DIBSTRETCHBLT),
    GpWmfRecordTypeDIBCreatePatternBrush   = GDIP_WMF_RECORD_TO_EMFPLUS(META_DIBCREATEPATTERNBRUSH),
    GpWmfRecordTypeStretchDIB              = GDIP_WMF_RECORD_TO_EMFPLUS(META_STRETCHDIB),
    GpWmfRecordTypeExtFloodFill            = GDIP_WMF_RECORD_TO_EMFPLUS(META_EXTFLOODFILL),
    GpWmfRecordTypeSetLayout               = GDIP_WMF_RECORD_TO_EMFPLUS(0x0149),  // META_SETLAYOUT
    GpWmfRecordTypeResetDC                 = GDIP_WMF_RECORD_TO_EMFPLUS(0x014C),  // META_RESETDC
    GpWmfRecordTypeStartDoc                = GDIP_WMF_RECORD_TO_EMFPLUS(0x014D),  // META_STARTDOC
    GpWmfRecordTypeStartPage               = GDIP_WMF_RECORD_TO_EMFPLUS(0x004F),  // META_STARTPAGE
    GpWmfRecordTypeEndPage                 = GDIP_WMF_RECORD_TO_EMFPLUS(0x0050),  // META_ENDPAGE
    GpWmfRecordTypeAbortDoc                = GDIP_WMF_RECORD_TO_EMFPLUS(0x0052),  // META_ABORTDOC
    GpWmfRecordTypeEndDoc                  = GDIP_WMF_RECORD_TO_EMFPLUS(0x005E),  // META_ENDDOC
    GpWmfRecordTypeDeleteObject            = GDIP_WMF_RECORD_TO_EMFPLUS(META_DELETEOBJECT),
    GpWmfRecordTypeCreatePalette           = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEPALETTE),
    GpWmfRecordTypeCreateBrush             = GDIP_WMF_RECORD_TO_EMFPLUS(0x00F8),  // META_CREATEBRUSH
    GpWmfRecordTypeCreatePatternBrush      = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEPATTERNBRUSH),
    GpWmfRecordTypeCreatePenIndirect       = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEPENINDIRECT),
    GpWmfRecordTypeCreateFontIndirect      = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEFONTINDIRECT),
    GpWmfRecordTypeCreateBrushIndirect     = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEBRUSHINDIRECT),
    GpWmfRecordTypeCreateBitmapIndirect    = GDIP_WMF_RECORD_TO_EMFPLUS(0x02FD),  // META_CREATEBITMAPINDIRECT
    GpWmfRecordTypeCreateBitmap            = GDIP_WMF_RECORD_TO_EMFPLUS(0x06FE),  // META_CREATEBITMAP
    GpWmfRecordTypeCreateRegion            = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEREGION),

    GpEmfRecordTypeHeader                  = EMR_HEADER,
    GpEmfRecordTypePolyBezier              = EMR_POLYBEZIER,
    GpEmfRecordTypePolygon                 = EMR_POLYGON,
    GpEmfRecordTypePolyline                = EMR_POLYLINE,
    GpEmfRecordTypePolyBezierTo            = EMR_POLYBEZIERTO,
    GpEmfRecordTypePolyLineTo              = EMR_POLYLINETO,
    GpEmfRecordTypePolyPolyline            = EMR_POLYPOLYLINE,
    GpEmfRecordTypePolyPolygon             = EMR_POLYPOLYGON,
    GpEmfRecordTypeSetWindowExtEx          = EMR_SETWINDOWEXTEX,
    GpEmfRecordTypeSetWindowOrgEx          = EMR_SETWINDOWORGEX,
    GpEmfRecordTypeSetViewportExtEx        = EMR_SETVIEWPORTEXTEX,
    GpEmfRecordTypeSetViewportOrgEx        = EMR_SETVIEWPORTORGEX,
    GpEmfRecordTypeSetBrushOrgEx           = EMR_SETBRUSHORGEX,
    GpEmfRecordTypeEOF                     = EMR_EOF,
    GpEmfRecordTypeSetPixelV               = EMR_SETPIXELV,
    GpEmfRecordTypeSetMapperFlags          = EMR_SETMAPPERFLAGS,
    GpEmfRecordTypeSetMapMode              = EMR_SETMAPMODE,
    GpEmfRecordTypeSetBkMode               = EMR_SETBKMODE,
    GpEmfRecordTypeSetPolyFillMode         = EMR_SETPOLYFILLMODE,
    GpEmfRecordTypeSetROP2                 = EMR_SETROP2,
    GpEmfRecordTypeSetStretchBltMode       = EMR_SETSTRETCHBLTMODE,
    GpEmfRecordTypeSetTextAlign            = EMR_SETTEXTALIGN,
    GpEmfRecordTypeSetColorAdjustment      = EMR_SETCOLORADJUSTMENT,
    GpEmfRecordTypeSetTextColor            = EMR_SETTEXTCOLOR,
    GpEmfRecordTypeSetBkColor              = EMR_SETBKCOLOR,
    GpEmfRecordTypeOffsetClipRgn           = EMR_OFFSETCLIPRGN,
    GpEmfRecordTypeMoveToEx                = EMR_MOVETOEX,
    GpEmfRecordTypeSetMetaRgn              = EMR_SETMETARGN,
    GpEmfRecordTypeExcludeClipRect         = EMR_EXCLUDECLIPRECT,
    GpEmfRecordTypeIntersectClipRect       = EMR_INTERSECTCLIPRECT,
    GpEmfRecordTypeScaleViewportExtEx      = EMR_SCALEVIEWPORTEXTEX,
    GpEmfRecordTypeScaleWindowExtEx        = EMR_SCALEWINDOWEXTEX,
    GpEmfRecordTypeSaveDC                  = EMR_SAVEDC,
    GpEmfRecordTypeRestoreDC               = EMR_RESTOREDC,
    GpEmfRecordTypeSetWorldTransform       = EMR_SETWORLDTRANSFORM,
    GpEmfRecordTypeModifyWorldTransform    = EMR_MODIFYWORLDTRANSFORM,
    GpEmfRecordTypeSelectObject            = EMR_SELECTOBJECT,
    GpEmfRecordTypeCreatePen               = EMR_CREATEPEN,
    GpEmfRecordTypeCreateBrushIndirect     = EMR_CREATEBRUSHINDIRECT,
    GpEmfRecordTypeDeleteObject            = EMR_DELETEOBJECT,
    GpEmfRecordTypeAngleArc                = EMR_ANGLEARC,
    GpEmfRecordTypeEllipse                 = EMR_ELLIPSE,
    GpEmfRecordTypeRectangle               = EMR_RECTANGLE,
    GpEmfRecordTypeRoundRect               = EMR_ROUNDRECT,
    GpEmfRecordTypeArc                     = EMR_ARC,
    GpEmfRecordTypeChord                   = EMR_CHORD,
    GpEmfRecordTypePie                     = EMR_PIE,
    GpEmfRecordTypeSelectPalette           = EMR_SELECTPALETTE,
    GpEmfRecordTypeCreatePalette           = EMR_CREATEPALETTE,
    GpEmfRecordTypeSetPaletteEntries       = EMR_SETPALETTEENTRIES,
    GpEmfRecordTypeResizePalette           = EMR_RESIZEPALETTE,
    GpEmfRecordTypeRealizePalette          = EMR_REALIZEPALETTE,
    GpEmfRecordTypeExtFloodFill            = EMR_EXTFLOODFILL,
    GpEmfRecordTypeLineTo                  = EMR_LINETO,
    GpEmfRecordTypeArcTo                   = EMR_ARCTO,
    GpEmfRecordTypePolyDraw                = EMR_POLYDRAW,
    GpEmfRecordTypeSetArcDirection         = EMR_SETARCDIRECTION,
    GpEmfRecordTypeSetMiterLimit           = EMR_SETMITERLIMIT,
    GpEmfRecordTypeBeginPath               = EMR_BEGINPATH,
    GpEmfRecordTypeEndPath                 = EMR_ENDPATH,
    GpEmfRecordTypeCloseFigure             = EMR_CLOSEFIGURE,
    GpEmfRecordTypeFillPath                = EMR_FILLPATH,
    GpEmfRecordTypeStrokeAndFillPath       = EMR_STROKEANDFILLPATH,
    GpEmfRecordTypeStrokePath              = EMR_STROKEPATH,
    GpEmfRecordTypeFlattenPath             = EMR_FLATTENPATH,
    GpEmfRecordTypeWidenPath               = EMR_WIDENPATH,
    GpEmfRecordTypeSelectClipPath          = EMR_SELECTCLIPPATH,
    GpEmfRecordTypeAbortPath               = EMR_ABORTPATH,
    GpEmfRecordTypeReserved_069            = 69,  // Not Used
    GpEmfRecordTypeGdiComment              = EMR_GDICOMMENT,
    GpEmfRecordTypeFillRgn                 = EMR_FILLRGN,
    GpEmfRecordTypeFrameRgn                = EMR_FRAMERGN,
    GpEmfRecordTypeInvertRgn               = EMR_INVERTRGN,
    GpEmfRecordTypePaintRgn                = EMR_PAINTRGN,
    GpEmfRecordTypeExtSelectClipRgn        = EMR_EXTSELECTCLIPRGN,
    GpEmfRecordTypeBitBlt                  = EMR_BITBLT,
    GpEmfRecordTypeStretchBlt              = EMR_STRETCHBLT,
    GpEmfRecordTypeMaskBlt                 = EMR_MASKBLT,
    GpEmfRecordTypePlgBlt                  = EMR_PLGBLT,
    GpEmfRecordTypeSetDIBitsToDevice       = EMR_SETDIBITSTODEVICE,
    GpEmfRecordTypeStretchDIBits           = EMR_STRETCHDIBITS,
    GpEmfRecordTypeExtCreateFontIndirect   = EMR_EXTCREATEFONTINDIRECTW,
    GpEmfRecordTypeExtTextOutA             = EMR_EXTTEXTOUTA,
    GpEmfRecordTypeExtTextOutW             = EMR_EXTTEXTOUTW,
    GpEmfRecordTypePolyBezier16            = EMR_POLYBEZIER16,
    GpEmfRecordTypePolygon16               = EMR_POLYGON16,
    GpEmfRecordTypePolyline16              = EMR_POLYLINE16,
    GpEmfRecordTypePolyBezierTo16          = EMR_POLYBEZIERTO16,
    GpEmfRecordTypePolylineTo16            = EMR_POLYLINETO16,
    GpEmfRecordTypePolyPolyline16          = EMR_POLYPOLYLINE16,
    GpEmfRecordTypePolyPolygon16           = EMR_POLYPOLYGON16,
    GpEmfRecordTypePolyDraw16              = EMR_POLYDRAW16,
    GpEmfRecordTypeCreateMonoBrush         = EMR_CREATEMONOBRUSH,
    GpEmfRecordTypeCreateDIBPatternBrushPt = EMR_CREATEDIBPATTERNBRUSHPT,
    GpEmfRecordTypeExtCreatePen            = EMR_EXTCREATEPEN,
    GpEmfRecordTypePolyTextOutA            = EMR_POLYTEXTOUTA,
    GpEmfRecordTypePolyTextOutW            = EMR_POLYTEXTOUTW,
    GpEmfRecordTypeSetICMMode              = 98,  // EMR_SETICMMODE,
    GpEmfRecordTypeCreateColorSpace        = 99,  // EMR_CREATECOLORSPACE,
    GpEmfRecordTypeSetColorSpace           = 100, // EMR_SETCOLORSPACE,
    GpEmfRecordTypeDeleteColorSpace        = 101, // EMR_DELETECOLORSPACE,
    GpEmfRecordTypeGLSRecord               = 102, // EMR_GLSRECORD,
    GpEmfRecordTypeGLSBoundedRecord        = 103, // EMR_GLSBOUNDEDRECORD,
    GpEmfRecordTypePixelFormat             = 104, // EMR_PIXELFORMAT,
    GpEmfRecordTypeDrawEscape              = 105, // EMR_RESERVED_105,
    GpEmfRecordTypeExtEscape               = 106, // EMR_RESERVED_106,
    GpEmfRecordTypeStartDoc                = 107, // EMR_RESERVED_107,
    GpEmfRecordTypeSmallTextOut            = 108, // EMR_RESERVED_108,
    GpEmfRecordTypeForceUFIMapping         = 109, // EMR_RESERVED_109,
    GpEmfRecordTypeNamedEscape             = 110, // EMR_RESERVED_110,
    GpEmfRecordTypeColorCorrectPalette     = 111, // EMR_COLORCORRECTPALETTE,
    GpEmfRecordTypeSetICMProfileA          = 112, // EMR_SETICMPROFILEA,
    GpEmfRecordTypeSetICMProfileW          = 113, // EMR_SETICMPROFILEW,
    GpEmfRecordTypeAlphaBlend              = 114, // EMR_ALPHABLEND,
    GpEmfRecordTypeSetLayout               = 115, // EMR_SETLAYOUT,
    GpEmfRecordTypeTransparentBlt          = 116, // EMR_TRANSPARENTBLT,
    GpEmfRecordTypeReserved_117            = 117, // Not Used
    GpEmfRecordTypeGradientFill            = 118, // EMR_GRADIENTFILL,
    GpEmfRecordTypeSetLinkedUFIs           = 119, // EMR_RESERVED_119,
    GpEmfRecordTypeSetTextJustification    = 120, // EMR_RESERVED_120,
    GpEmfRecordTypeColorMatchToTargetW     = 121, // EMR_COLORMATCHTOTARGETW,
    GpEmfRecordTypeCreateColorSpaceW       = 122, // EMR_CREATECOLORSPACEW,
    GpEmfRecordTypeMax                     = 122,
    GpEmfRecordTypeMin                     = 1,

    // That is the END of the GDI EMF records.

    // Now we start the list of EMF+ records.  We leave quite
    // a bit of room here for the addition of any new GDI
    // records that may be added later.

    GpEmfPlusRecordTypeInvalid = GDIP_EMFPLUS_RECORD_BASE,
    GpEmfPlusRecordTypeHeader,
    GpEmfPlusRecordTypeEndOfFile,

    GpEmfPlusRecordTypeComment,

    GpEmfPlusRecordTypeGetDC,

    GpEmfPlusRecordTypeMultiFormatStart,
    GpEmfPlusRecordTypeMultiFormatSection,
    GpEmfPlusRecordTypeMultiFormatEnd,

    // For all persistent objects
    
    GpEmfPlusRecordTypeObject,

    // Drawing Records
    
    GpEmfPlusRecordTypeClear,
    GpEmfPlusRecordTypeFillRects,
    GpEmfPlusRecordTypeDrawRects,
    GpEmfPlusRecordTypeFillPolygon,
    GpEmfPlusRecordTypeDrawLines,
    GpEmfPlusRecordTypeFillEllipse,
    GpEmfPlusRecordTypeDrawEllipse,
    GpEmfPlusRecordTypeFillPie,
    GpEmfPlusRecordTypeDrawPie,
    GpEmfPlusRecordTypeDrawArc,
    GpEmfPlusRecordTypeFillRegion,
    GpEmfPlusRecordTypeFillPath,
    GpEmfPlusRecordTypeDrawPath,
    GpEmfPlusRecordTypeFillClosedCurve,
    GpEmfPlusRecordTypeDrawClosedCurve,
    GpEmfPlusRecordTypeDrawCurve,
    GpEmfPlusRecordTypeDrawBeziers,
    GpEmfPlusRecordTypeDrawImage,
    GpEmfPlusRecordTypeDrawImagePoints,
    GpEmfPlusRecordTypeDrawString,

    // Graphics State Records
    
    GpEmfPlusRecordTypeSetRenderingOrigin,
    GpEmfPlusRecordTypeSetAntiAliasMode,
    GpEmfPlusRecordTypeSetTextRenderingHint,
    GpEmfPlusRecordTypeSetTextContrast,
    GpEmfPlusRecordTypeSetInterpolationMode,
    GpEmfPlusRecordTypeSetPixelOffsetMode,
    GpEmfPlusRecordTypeSetCompositingMode,
    GpEmfPlusRecordTypeSetCompositingQuality,
    GpEmfPlusRecordTypeSave,
    GpEmfPlusRecordTypeRestore,
    GpEmfPlusRecordTypeBeginContainer,
    GpEmfPlusRecordTypeBeginContainerNoParams,
    GpEmfPlusRecordTypeEndContainer,
    GpEmfPlusRecordTypeSetWorldTransform,
    GpEmfPlusRecordTypeResetWorldTransform,
    GpEmfPlusRecordTypeMultiplyWorldTransform,
    GpEmfPlusRecordTypeTranslateWorldTransform,
    GpEmfPlusRecordTypeScaleWorldTransform,
    GpEmfPlusRecordTypeRotateWorldTransform,
    GpEmfPlusRecordTypeSetPageTransform,
    GpEmfPlusRecordTypeResetClip,
    GpEmfPlusRecordTypeSetClipRect,
    GpEmfPlusRecordTypeSetClipPath,
    GpEmfPlusRecordTypeSetClipRegion,
    GpEmfPlusRecordTypeOffsetClip,

    GpEmfPlusRecordTypeDrawDriverString,
#if (GDIPVER >= 0x0110)
    GpEmfPlusRecordTypeStrokeFillPath,
    GpEmfPlusRecordTypeSerializableObject,

    GpEmfPlusRecordTypeSetTSGraphics,
    GpEmfPlusRecordTypeSetTSClip,
#endif
    // NOTE: New records *must* be added immediately before this line.

    GpEmfPlusRecordTotal,

    GpEmfPlusRecordTypeMax = GpEmfPlusRecordTotal-1,
    GpEmfPlusRecordTypeMin = GpEmfPlusRecordTypeHeader,
} GpEmfPlusRecordType;

//---------------------------------------------------------------------------
// StringFormatFlags
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// String format flags
//
//  DirectionRightToLeft          - For horizontal text, the reading order is
//                                  right to left. This value is called
//                                  the base embedding level by the Unicode
//                                  bidirectional engine.
//                                  For vertical text, columns are read from
//                                  right to left.
//                                  By default, horizontal or vertical text is
//                                  read from left to right.
//
//  DirectionVertical             - Individual lines of text are vertical. In
//                                  each line, characters progress from top to
//                                  bottom.
//                                  By default, lines of text are horizontal,
//                                  each new line below the previous line.
//
//  NoFitBlackBox                 - Allows parts of glyphs to overhang the
//                                  bounding rectangle.
//                                  By default glyphs are first aligned
//                                  inside the margines, then any glyphs which
//                                  still overhang the bounding box are
//                                  repositioned to avoid any overhang.
//                                  For example when an italic
//                                  lower case letter f in a font such as
//                                  Garamond is aligned at the far left of a
//                                  rectangle, the lower part of the f will
//                                  reach slightly further left than the left
//                                  edge of the rectangle. Setting this flag
//                                  will ensure the character aligns visually
//                                  with the lines above and below, but may
//                                  cause some pixels outside the formatting
//                                  rectangle to be clipped or painted.
//
//  DisplayFormatControl          - Causes control characters such as the
//                                  left-to-right mark to be shown in the
//                                  output with a representative glyph.
//
//  NoFontFallback                - Disables fallback to alternate fonts for
//                                  characters not supported in the requested
//                                  font. Any missing characters will be
//                                  be displayed with the fonts missing glyph,
//                                  usually an open square.
//
//  NoWrap                        - Disables wrapping of text between lines
//                                  when formatting within a rectangle.
//                                  NoWrap is implied when a point is passed
//                                  instead of a rectangle, or when the
//                                  specified rectangle has a zero line length.
//
//  NoClip                        - By default text is clipped to the
//                                  formatting rectangle. Setting NoClip
//                                  allows overhanging pixels to affect the
//                                  device outside the formatting rectangle.
//                                  Pixels at the end of the line may be
//                                  affected if the glyphs overhang their
//                                  cells, and either the NoFitBlackBox flag
//                                  has been set, or the glyph extends to far
//                                  to be fitted.
//                                  Pixels above/before the first line or
//                                  below/after the last line may be affected
//                                  if the glyphs extend beyond their cell
//                                  ascent / descent. This can occur rarely
//                                  with unusual diacritic mark combinations.

//---------------------------------------------------------------------------

typedef enum GpStringFormatFlags
{
    GpStringFormatFlagsDirectionRightToLeft        = 0x00000001,
    GpStringFormatFlagsDirectionVertical           = 0x00000002,
    GpStringFormatFlagsNoFitBlackBox               = 0x00000004,
    GpStringFormatFlagsDisplayFormatControl        = 0x00000020,
    GpStringFormatFlagsNoFontFallback              = 0x00000400,
    GpStringFormatFlagsMeasureTrailingSpaces       = 0x00000800,
    GpStringFormatFlagsNoWrap                      = 0x00001000,
    GpStringFormatFlagsLineLimit                   = 0x00002000,

    GpStringFormatFlagsNoClip                      = 0x00004000,
    GpStringFormatFlagsBypassGDI                   = 0x80000000
} GpStringFormatFlags;

//---------------------------------------------------------------------------
// StringTrimming
//---------------------------------------------------------------------------

typedef enum GpStringTrimming {
    GpStringTrimmingNone              = 0,
    GpStringTrimmingCharacter         = 1,
    GpStringTrimmingWord              = 2,
    GpStringTrimmingEllipsisCharacter = 3,
    GpStringTrimmingEllipsisWord      = 4,
    GpStringTrimmingEllipsisPath      = 5
} GpStringTrimming;

//---------------------------------------------------------------------------
// National language digit substitution
//---------------------------------------------------------------------------

typedef enum GpStringDigitSubstitute
{
    GpStringDigitSubstituteUser        = 0,  // As NLS setting
    GpStringDigitSubstituteNone        = 1,
    GpStringDigitSubstituteNational    = 2,
    GpStringDigitSubstituteTraditional = 3
} GpStringDigitSubstitute;

//---------------------------------------------------------------------------
// Hotkey prefix interpretation
//---------------------------------------------------------------------------

typedef enum GpHotkeyPrefix
{
    GpHotkeyPrefixNone        = 0,
    GpHotkeyPrefixShow        = 1,
    GpHotkeyPrefixHide        = 2
} GpHotkeyPrefix;

//---------------------------------------------------------------------------
// String alignment flags
//---------------------------------------------------------------------------

typedef enum GpStringAlignment
{
    // Left edge for left-to-right text,
    // right for right-to-left text,
    // and top for vertical
    GpStringAlignmentNear   = 0,
    GpStringAlignmentCenter = 1,
    GpStringAlignmentFar    = 2
} GpStringAlignment;

//---------------------------------------------------------------------------
// DriverStringOptions
//---------------------------------------------------------------------------

typedef enum GpDriverStringOptions
{
    GpDriverStringOptionsCmapLookup             = 1,
    GpDriverStringOptionsVertical               = 2,
    GpDriverStringOptionsRealizedAdvance        = 4,
    GpDriverStringOptionsLimitSubpixel          = 8
} GpDriverStringOptions;

//---------------------------------------------------------------------------
// Flush Intention flags
//---------------------------------------------------------------------------

typedef enum GpFlushIntention
{
    GpFlushIntentionFlush = 0,        // Flush all batched rendering operations
    GpFlushIntentionSync = 1          // Flush all batched rendering operations
                                    // and wait for them to complete
} GpFlushIntention;

//---------------------------------------------------------------------------
// Image encoder parameter related types
//---------------------------------------------------------------------------

typedef enum GpEncoderParameterValueType
{
    GpEncoderParameterValueTypeByte           = 1,    // 8-bit unsigned int
    GpEncoderParameterValueTypeASCII          = 2,    // 8-bit byte containing one 7-bit ASCII
                                                    // code. NULL terminated.
    GpEncoderParameterValueTypeShort          = 3,    // 16-bit unsigned int
    GpEncoderParameterValueTypeLong           = 4,    // 32-bit unsigned int
    GpEncoderParameterValueTypeRational       = 5,    // Two Longs. The first Long is the
                                                    // numerator, the second Long expresses the
                                                    // denomintor.
    GpEncoderParameterValueTypeLongRange      = 6,    // Two longs which specify a range of
                                                    // integer values. The first Long specifies
                                                    // the lower end and the second one
                                                    // specifies the higher end. All values
                                                    // are inclusive at both ends
    GpEncoderParameterValueTypeUndefined      = 7,    // 8-bit byte that can take any value
                                                    // depending on field definition
    GpEncoderParameterValueTypeRationalRange  = 8,    // Two Rationals. The first Rational
                                                    // specifies the lower end and the second
                                                    // specifies the higher end. All values
                                                    // are inclusive at both ends
#if (GDIPVER >= 0x0110)
    GpEncoderParameterValueTypePointer        = 9     // a pointer to a parameter defined data.
#endif //(GDIPVER >= 0x0110)
} GpEncoderParameterValueType;

//---------------------------------------------------------------------------
// Image encoder value types
//---------------------------------------------------------------------------

typedef enum GpEncoderValue
{
    GpEncoderValueColorTypeCMYK,
    GpEncoderValueColorTypeYCCK,
    GpEncoderValueCompressionLZW,
    GpEncoderValueCompressionCCITT3,
    GpEncoderValueCompressionCCITT4,
    GpEncoderValueCompressionRle,
    GpEncoderValueCompressionNone,
    GpEncoderValueScanMethodInterlaced,
    GpEncoderValueScanMethodNonInterlaced,
    GpEncoderValueVersionGif87,
    GpEncoderValueVersionGif89,
    GpEncoderValueRenderProgressive,
    GpEncoderValueRenderNonProgressive,
    GpEncoderValueTransformRotate90,
    GpEncoderValueTransformRotate180,
    GpEncoderValueTransformRotate270,
    GpEncoderValueTransformFlipHorizontal,
    GpEncoderValueTransformFlipVertical,
    GpEncoderValueMultiFrame,
    GpEncoderValueLastFrame,
    GpEncoderValueFlush,
    GpEncoderValueFrameDimensionTime,
    GpEncoderValueFrameDimensionResolution,
    GpEncoderValueFrameDimensionPage,
#if (GDIPVER >= 0x0110)
    GpEncoderValueColorTypeGray,
    GpEncoderValueColorTypeRGB,
#endif
} GpEncoderValue;

//---------------------------------------------------------------------------
// Conversion of Emf To WMF Bits flags
//---------------------------------------------------------------------------

typedef enum GpEmfToWmfBitsFlags
{
    GpEmfToWmfBitsFlagsDefault          = 0x00000000,
    GpEmfToWmfBitsFlagsEmbedEmf         = 0x00000001,
    GpEmfToWmfBitsFlagsIncludePlaceable = 0x00000002,
    GpEmfToWmfBitsFlagsNoXORClip        = 0x00000004
} GpEmfToWmfBitsFlags;

#if (GDIPVER >= 0x0110)
//---------------------------------------------------------------------------
// Conversion of Emf To Emf+ Bits flags
//---------------------------------------------------------------------------

typedef enum GpConvertToEmfPlusFlags
{
    GpConvertToEmfPlusFlagsDefault       = 0x00000000,
    GpConvertToEmfPlusFlagsRopUsed       = 0x00000001,
    GpConvertToEmfPlusFlagsText          = 0x00000002,
    GpConvertToEmfPlusFlagsInvalidRecord = 0x00000004
} GpConvertToEmfPlusFlags;
#endif


//---------------------------------------------------------------------------
// Test Control flags
//---------------------------------------------------------------------------

typedef enum GpTestControlEnum
{
    GpTestControlForceBilinear = 0,
    GpTestControlNoICM = 1,
    GpTestControlGetBuildNumber = 2
} GpTestControlEnum;

//--------------------------------------------------------------------------
// Callback functions
//--------------------------------------------------------------------------

typedef BOOL (CALLBACK * GpImageAbort)(VOID *);
typedef GpImageAbort GpDrawImageAbort;
typedef GpImageAbort GpGetThumbnailImageAbort;

// Callback for EnumerateMetafile methods.  The parameters are:

//      recordType      WMF, EMF, or EMF+ record type
//      flags           (always 0 for WMF/EMF records)
//      dataSize        size of the record data (in bytes), or 0 if no data
//      data            pointer to the record data, or NULL if no data
//      callbackData    pointer to callbackData, if any

// This method can then call Metafile::PlayRecord to play the
// record that was just enumerated.  If this method  returns
// FALSE, the enumeration process is aborted.  Otherwise, it continues.

typedef BOOL (CALLBACK * GpEnumerateMetafileProc)(GpEmfPlusRecordType,UINT,UINT,const BYTE*,VOID*);

#if (GDIPVER >= 0x0110)
// This is the main GDI+ Abort interface

#undef INTERFACE
#define INTERFACE GdiplusAbort
DECLARE_INTERFACE(GdiplusAbort)
{
    STDMETHOD(Abort)(THIS) PURE;
};

#if !defined(__cplusplus) || defined(CINTERFACE)
#define GdiplusAbort_Abort(p)                    (p)->lpVtbl->Abort(p)
#else
#define GdiplusAbort_Abort(p)                    (p)->Abort()
#endif

#endif //(GDIPVER >= 0x0110)

//--------------------------------------------------------------------------
// Primitive data types
//
// NOTE:
//  Types already defined in standard header files:
//      INT8
//      UINT8
//      INT16
//      UINT16
//      INT32
//      UINT32
//      INT64
//      UINT64
//
//  Avoid using the following types:
//      LONG - use INT
//      ULONG - use UINT
//      DWORD - use UINT32
//--------------------------------------------------------------------------

typedef float REAL;

#define REAL_MAX            FLT_MAX
#define REAL_MIN            FLT_MIN
#define REAL_TOLERANCE     (FLT_MIN * 100)
#define REAL_EPSILON        1.192092896e-07F        /* FLT_EPSILON */

//--------------------------------------------------------------------------
// Status return values from GDI+ methods
//--------------------------------------------------------------------------

typedef enum GpStatus
{
    GpOk = 0,
    GpGenericError = 1,
    GpInvalidParameter = 2,
    GpOutOfMemory = 3,
    GpObjectBusy = 4,
    GpInsufficientBuffer = 5,
    GpNotImplemented = 6,
    GpWin32Error = 7,
    GpWrongState = 8,
    GpAborted = 9,
    GpFileNotFound = 10,
    GpValueOverflow = 11,
    GpAccessDenied = 12,
    GpUnknownImageFormat = 13,
    GpFontFamilyNotFound = 14,
    GpFontStyleNotFound = 15,
    GpNotTrueTypeFont = 16,
    GpUnsupportedGdiplusVersion = 17,
    GpGdiplusNotInitialized = 18,
    GpPropertyNotFound = 19,
    GpPropertyNotSupported = 20,
#if (GDIPVER >= 0x0110)
    GpProfileNotFound = 21,
#endif //(GDIPVER >= 0x0110)
} GpStatus;

//--------------------------------------------------------------------------
// Represents a dimension in a 2D coordinate system (floating-point coordinates)
//--------------------------------------------------------------------------

typedef struct GpSizeF
{
    REAL Width;
    REAL Height;
} GpSizeF;

FORCEINLINE UINT WINGDIPAPI
GdipSizeAdd(OUT GpSizeF* sz, IN const GpSizeF *left, IN const GpSizeF *right)
{
    sz->Width = left->Width + right->Width;
    sz->Height = left->Height + right->Height;
}

FORCEINLINE UINT WINGDIPAPI
GdipSizeSub(OUT GpSizeF* sz, IN const GpSizeF *left, IN const GpSizeF *right)
{
    sz->Width = left->Width - right->Width;
    sz->Height = left->Height - right->Height;
}

FORCEINLINE BOOL WINGDIPAPI
GdipSizeEquals(IN const GpSizeF *left, IN const GpSizeF *right)
{
    return (left->Width == right->Width) && (left->Height == right->Height);
}

FORCEINLINE BOOL WINGDIPAPI
GdipSizeEmpty(IN const GpSizeF* sz)
{
    return (sz->Width == 0.0f && sz->Height == 0.0f);
}

//--------------------------------------------------------------------------
// Represents a dimension in a 2D coordinate system (integer coordinates)
//--------------------------------------------------------------------------

typedef struct GpSize
{
    INT Width;
    INT Height;
} GpSize;

FORCEINLINE UINT WINGDIPAPI
GdipSizeAddI(OUT GpSize* sz, IN const GpSize *left, IN const GpSize *right)
{
    sz->Width = left->Width + right->Width;
    sz->Height = left->Height + right->Height;
}

FORCEINLINE UINT WINGDIPAPI
GdipSizeSubI(OUT GpSize* sz, IN const GpSize *left, IN const GpSize *right)
{
    sz->Width = left->Width - right->Width;
    sz->Height = left->Height - right->Height;
}

FORCEINLINE BOOL WINGDIPAPI
GdipSizeEqualsI(IN const GpSize *left, IN const GpSize *right)
{
    return (left->Width == right->Width) && (left->Height == right->Height);
}

FORCEINLINE BOOL WINGDIPAPI
GdipSizeEmptyI(IN const GpSize* sz)
{
    return (sz->Width == 0 && sz->Height == 0);
}

//--------------------------------------------------------------------------
// Represents a location in a 2D coordinate system (floating-point coordinates)
//--------------------------------------------------------------------------

typedef struct GpPointF
{
    REAL X;
    REAL Y;
} GpPointF;

FORCEINLINE VOID WINGDIPAPI
GdipPointAdd(OUT GpPointF* point, IN const GpPointF *left, IN const GpPointF *right)
{
    point->X = left->X + right->X;
    point->Y = left->Y + right->Y;
}

FORCEINLINE VOID WINGDIPAPI
GdipPointSub(OUT GpPointF* point, IN const GpPointF *left, IN const GpPointF *right)
{
    point->X = left->X - right->X;
    point->Y = left->Y - right->Y;
}

FORCEINLINE BOOL WINGDIPAPI
GdipPointEquals(IN const GpPointF *left, IN const GpPointF *right)
{
    return (left->X == right->X) && (left->Y == right->Y);
}

//--------------------------------------------------------------------------
// Represents a location in a 2D coordinate system (integer coordinates)
//--------------------------------------------------------------------------

typedef struct GpPoint
{
    INT X;
    INT Y;
} GpPoint;

FORCEINLINE VOID WINGDIPAPI
GdipPointAddI(OUT GpPoint* point, IN const GpPoint *left, IN const GpPoint *right)
{
    point->X = left->X + right->X;
    point->Y = left->Y + right->Y;
}

FORCEINLINE VOID WINGDIPAPI
GdipPointSubI(OUT GpPoint* point, IN const GpPoint *left, IN const GpPoint *right)
{
    point->X = left->X - right->X;
    point->Y = left->Y - right->Y;
}

FORCEINLINE BOOL WINGDIPAPI
GdipPointEqualsI(IN const GpPoint *left, IN const GpPoint *right)
{
    return (left->X == right->X) && (left->Y == right->Y);
}

//--------------------------------------------------------------------------
// Represents a rectangle in a 2D coordinate system (floating-point coordinates)
//--------------------------------------------------------------------------

typedef struct GpRectF
{
    union {
        struct {
            GpPointF Location;
            GpSizeF Size;
        };
        struct {
            REAL X;
            REAL Y;
            REAL Width;
            REAL Height;
        };
    };
} GpRectF;

FORCEINLINE REAL WINGDIPAPI
GdipRectangleGetRight(IN const GpRectF *rect)
{
    return rect->X+rect->Width;
}

FORCEINLINE REAL WINGDIPAPI
GdipRectangleGetBottom(IN const GpRectF *rect)
{
    return rect->Y+rect->Height;
}

FORCEINLINE BOOL WINGDIPAPI
GdipRectangleIsEmptyArea(IN const GpRectF *rect)
{
    return (rect->Width <= REAL_EPSILON) || (rect->Height <= REAL_EPSILON);
}

FORCEINLINE BOOL WINGDIPAPI
GdipRectangleEquals(IN const GpRectF *left, IN const GpRectF *right)
{
    return  left->X == right->X &&
            left->Y == right->Y &&
            left->Width == right->Width &&
            left->Height == right->Height;
}

FORCEINLINE BOOL WINGDIPAPI
GdipRectangleContains(IN const GpRectF *rect, IN REAL x, IN REAL y)
{
    return  x >= rect->X && x < rect->X+rect->Width &&
            y >= rect->Y && y < rect->Y+rect->Height;
}

FORCEINLINE BOOL WINGDIPAPI
GdipRectangleContainsRect(IN const GpRectF *left, IN const GpRectF *right)
{
    return  (left->X <= right->X) && (right->X + right->Width) <= (left->X + left->Width) &&
            (left->Y <= right->Y) && (right->Y + right->Height) <= (left->Y + left->Height);
}

FORCEINLINE VOID WINGDIPAPI
GdipRectangleInflate(IN OUT GpRectF *rect, IN REAL dx, IN REAL dy)
{
    rect->X -= dx;
    rect->Y -= dy;
    rect->Width += 2*dx;
    rect->Height += 2*dy;
}

FORCEINLINE BOOL WINGDIPAPI
GdipRectangleIntersect(OUT GpRectF* c, IN const GpRectF* a, IN const GpRectF* b)
{
    REAL aRight = a->X + a->Width;
    REAL aBottom = a->Y + a->Height;
    REAL bRight = b->X + b->Width;
    REAL bBottom = b->Y + b->Height;

    c->X = max(a->X, b->X);
    c->Y = max(a->Y, b->Y);
    c->Width = min(aRight, bRight) - c->X;
    c->Height = min(aBottom, bBottom) - c->Y;
    return !GdipRectangleIsEmptyArea(c);
}

FORCEINLINE BOOL WINGDIPAPI
GdipRectangleIntersectsWith(IN const GpRectF *a, IN const GpRectF *b)
{
    REAL aRight = a->X + a->Width;
    REAL aBottom = a->Y + a->Height;
    REAL bRight = b->X + b->Width;
    REAL bBottom = b->Y + b->Height;

    return (a->X < bRight &&
            a->Y < bBottom &&
            aRight > b->X &&
            aBottom > b->Y);
}

FORCEINLINE BOOL WINGDIPAPI
GdipRectangleUnion(OUT GpRectF* c, IN const GpRectF* a, IN const GpRectF* b)
{
    REAL aRight = a->X + a->Width;
    REAL aBottom = a->Y + a->Height;
    REAL bRight = b->X + b->Width;
    REAL bBottom = b->Y + b->Height;

    c->X = min(a->X, b->X);
    c->Y = min(a->Y, b->Y);
    c->Width = max(aRight, bRight) - c->X;
    c->Height = max(aBottom, bBottom) - c->Y;
    return !GdipRectangleIsEmptyArea(c);
}

FORCEINLINE VOID WINGDIPAPI
GdipRectangleOffset(IN OUT GpRectF *rect, IN REAL dx, IN REAL dy)
{
    rect->X += dx;
    rect->Y += dy;
}

//--------------------------------------------------------------------------
// Represents a rectangle in a 2D coordinate system (integer coordinates)
//--------------------------------------------------------------------------

typedef struct GpRect
{
    union {
        struct {
            GpPoint Location;
            GpSize Size;
        };
        struct {
            INT X;
            INT Y;
            INT Width;
            INT Height;
        };
    };
} GpRect;

FORCEINLINE INT WINGDIPAPI
GdipRectangleGetRightI(IN const GpRect *rect)
{
    return rect->X+rect->Width;
}

FORCEINLINE INT WINGDIPAPI
GdipRectangleGetBottomI(IN const GpRect *rect)
{
    return rect->Y+rect->Height;
}

FORCEINLINE BOOL WINGDIPAPI
GdipRectangleIsEmptyAreaI(IN const GpRect *rect)
{
    return (rect->Width <= REAL_EPSILON) || (rect->Height <= REAL_EPSILON);
}

FORCEINLINE BOOL WINGDIPAPI
GdipRectangleEqualsI(IN const GpRect *left, IN const GpRect *right)
{
    return  left->X == right->X &&
            left->Y == right->Y &&
            left->Width == right->Width &&
            left->Height == right->Height;
}

FORCEINLINE BOOL WINGDIPAPI
GdipRectangleContainsI(IN const GpRect *rect, IN INT x, IN INT y)
{
    return  x >= rect->X && x < rect->X+rect->Width &&
            y >= rect->Y && y < rect->Y+rect->Height;
}

FORCEINLINE BOOL WINGDIPAPI
GdipRectangleContainsRectI(IN const GpRect *left, IN const GpRect *right)
{
    return  (left->X <= right->X) && (right->X + right->Width) <= (left->X + left->Width) &&
            (left->Y <= right->Y) && (right->Y + right->Height) <= (left->Y + left->Height);
}

FORCEINLINE VOID WINGDIPAPI
GdipRectangleInflateI(IN OUT GpRect *rect, IN INT dx, IN INT dy)
{
    rect->X -= dx;
    rect->Y -= dy;
    rect->Width += 2*dx;
    rect->Height += 2*dy;
}

FORCEINLINE BOOL WINGDIPAPI
GdipRectangleIntersectI(OUT GpRect* c, IN const GpRect* a, IN const GpRect* b)
{
    INT aRight = a->X + a->Width;
    INT aBottom = a->Y + a->Height;
    INT bRight = b->X + b->Width;
    INT bBottom = b->Y + b->Height;

    c->X = max(a->X, b->X);
    c->Y = max(a->Y, b->Y);
    c->Width = min(aRight, bRight) - c->X;
    c->Height = min(aBottom, bBottom) - c->Y;
    return !GdipRectangleIsEmptyAreaI(c);
}

FORCEINLINE BOOL WINGDIPAPI
GdipRectangleIntersectsWithI(IN const GpRect *a, IN const GpRect *b)
{
    INT aRight = a->X + a->Width;
    INT aBottom = a->Y + a->Height;
    INT bRight = b->X + b->Width;
    INT bBottom = b->Y + b->Height;

    return (a->X < bRight &&
            a->Y < bBottom &&
            aRight > b->X &&
            aBottom > b->Y);
}

FORCEINLINE BOOL WINGDIPAPI
GdipRectangleUnionI(OUT GpRect* c, IN const GpRect* a, IN const GpRect* b)
{
    INT aRight = a->X + a->Width;
    INT aBottom = a->Y + a->Height;
    INT bRight = b->X + b->Width;
    INT bBottom = b->Y + b->Height;

    c->X = min(a->X, b->X);
    c->Y = min(a->Y, b->Y);
    c->Width = max(aRight, bRight) - c->X;
    c->Height = max(aBottom, bBottom) - c->Y;
    return !GdipRectangleIsEmptyAreaI(c);
}

FORCEINLINE VOID WINGDIPAPI
GdipRectangleOffsetI(IN OUT GpRect *rect, IN INT dx, IN INT dy)
{
    rect->X += dx;
    rect->Y += dy;
}

typedef struct GpPathData
{
    INT Count;
    GpPointF* Points;
    __field_ecount_opt(Count) BYTE* Types;
} GpPathData;

typedef struct GpCharacterRange
{
    INT First;
    INT Length;
} GpCharacterRange;

typedef enum GpDebugEventLevel
{
    GpDebugEventLevelFatal,
    GpDebugEventLevelWarning
} GpDebugEventLevel;

// Callback function that GDI+ can call, on debug builds, for assertions
// and warnings.

typedef VOID (WINGDIPAPI *GpDebugEventProc)(GpDebugEventLevel level, CHAR *message);

// Notification functions which the user must call appropriately if
// "SuppressBackgroundThread" (below) is set.

typedef GpStatus (WINGDIPAPI *GpNotificationHookProc)(OUT ULONG_PTR *token);
typedef VOID (WINGDIPAPI *GpNotificationUnhookProc)(ULONG_PTR token);

// Input structure for GdiplusStartup()
typedef struct GdiplusStartupInput
{
    UINT32 GdiplusVersion;             // Must be 1  (or 2 for the Ex version)
    GpDebugEventProc DebugEventCallback; // Ignored on free builds
    BOOL SuppressBackgroundThread;     // FALSE unless you're prepared to call 
                                       // the hook/unhook functions properly
    BOOL SuppressExternalCodecs;       // FALSE unless you want GDI+ only to use
                                       // its internal image codecs.
} GdiplusStartupInput;

#if (GDIPVER >= 0x0110)
typedef struct GdiplusStartupInputEx
{
    GdiplusStartupInput StartupInput;
    INT StartupParameters;  // Do we not set the FPU rounding mode
} GdiplusStartupInputEx;

typedef enum GdiplusStartupParams
{
    GdiplusStartupDefault = 0,
    GdiplusStartupNoSetRound = 1,
    GdiplusStartupSetPSValue = 2,
    GdiplusStartupTransparencyMask = 0xFF000000
} GdiplusStartupParams;

#endif


// Output structure for GdiplusStartup()
typedef struct GdiplusStartupOutput
{
    // The following 2 fields are NULL if SuppressBackgroundThread is FALSE.
    // Otherwise, they are functions which must be called appropriately to
    // replace the background thread.
    //
    // These should be called on the application's main message loop - i.e.
    // a message loop which is active for the lifetime of GDI+.
    // "NotificationHook" should be called before starting the loop,
    // and "NotificationUnhook" should be called after the loop ends.
    
    GpNotificationHookProc NotificationHook;
    GpNotificationUnhookProc NotificationUnhook;
} GdiplusStartupOutput;

// GDI+ initialization. Must not be called from DllMain - can cause deadlock.
//
// Must be called before GDI+ API's or constructors are used.
//
// token  - may not be NULL - accepts a token to be passed in the corresponding
//          GdiplusShutdown call.
// input  - may not be NULL
// output - may be NULL only if input->SuppressBackgroundThread is FALSE.

DECLSPEC_IMPORT GpStatus WINGDIPAPI GdiplusStartup(
    OUT ULONG_PTR *token,
    const GdiplusStartupInput *input,
    OUT GdiplusStartupOutput *output);

// GDI+ termination. Must be called before GDI+ is unloaded. 
// Must not be called from DllMain - can cause deadlock.
//
// GDI+ API's may not be called after GdiplusShutdown. Pay careful attention
// to GDI+ object destructors.

DECLSPEC_IMPORT VOID WINGDIPAPI GdiplusShutdown(ULONG_PTR token);

typedef DWORD ARGB;
typedef DWORDLONG ARGB64;

#define ALPHA_SHIFT 24
#define RED_SHIFT   16
#define GREEN_SHIFT 8
#define BLUE_SHIFT  0
#define ALPHA_MASK  ((ARGB) 0xff << ALPHA_SHIFT)

// In-memory pixel data formats:
// bits 0-7 = format index
// bits 8-15 = pixel size (in bits)
// bits 16-23 = flags
// bits 24-31 = reserved

typedef enum GpPixelFormat
{
    GpPixelFormatIndexed      = 0x00010000, // Indexes into a palette
    GpPixelFormatGDI          = 0x00020000, // Is a GDI-supported format
    GpPixelFormatAlpha        = 0x00040000, // Has an alpha component
    GpPixelFormatPAlpha       = 0x00080000, // Pre-multiplied alpha
    GpPixelFormatExtended     = 0x00100000, // Extended color 16 bits/channel
    GpPixelFormatCanonical    = 0x00200000, 

    GpPixelFormatUndefined       = 0,
    GpPixelFormatDontCare        = 0,

    GpPixelFormat1bppIndexed     = (1 | ( 1 << 8) | GpPixelFormatIndexed | GpPixelFormatGDI),
    GpPixelFormat4bppIndexed     = (2 | ( 4 << 8) | GpPixelFormatIndexed | GpPixelFormatGDI),
    GpPixelFormat8bppIndexed     = (3 | ( 8 << 8) | GpPixelFormatIndexed | GpPixelFormatGDI),
    GpPixelFormat16bppGrayScale  = (4 | (16 << 8) | GpPixelFormatExtended),
    GpPixelFormat16bppRGB555     = (5 | (16 << 8) | GpPixelFormatGDI),
    GpPixelFormat16bppRGB565     = (6 | (16 << 8) | GpPixelFormatGDI),
    GpPixelFormat16bppARGB1555   = (7 | (16 << 8) | GpPixelFormatAlpha | GpPixelFormatGDI),
    GpPixelFormat24bppRGB        = (8 | (24 << 8) | GpPixelFormatGDI),
    GpPixelFormat32bppRGB        = (9 | (32 << 8) | GpPixelFormatGDI),
    GpPixelFormat32bppARGB       = (10 | (32 << 8) | GpPixelFormatAlpha | GpPixelFormatGDI | GpPixelFormatCanonical),
    GpPixelFormat32bppPARGB      = (11 | (32 << 8) | GpPixelFormatAlpha | GpPixelFormatPAlpha | GpPixelFormatGDI),
    GpPixelFormat48bppRGB        = (12 | (48 << 8) | GpPixelFormatExtended),
    GpPixelFormat64bppARGB       = (13 | (64 << 8) | GpPixelFormatAlpha  | GpPixelFormatCanonical | GpPixelFormatExtended),
    GpPixelFormat64bppPARGB      = (14 | (64 << 8) | GpPixelFormatAlpha  | GpPixelFormatPAlpha | GpPixelFormatExtended),
    GpPixelFormat32bppCMYK       = (15 | (32 << 8)),
    GpPixelFormatMax             = 16,
} GpPixelFormat;

FORCEINLINE UINT WINGDIPAPI
GdipGetPixelFormatSize(GpPixelFormat pixfmt)
{
    return (pixfmt >> 8) & 0xff;
}

FORCEINLINE BOOL WINGDIPAPI
GdipIsIndexedPixelFormat(GpPixelFormat pixfmt)
{
    return (pixfmt & GpPixelFormatIndexed) != 0;
}

FORCEINLINE BOOL WINGDIPAPI
GdipIsAlphaPixelFormat(GpPixelFormat pixfmt)
{
   return (pixfmt & GpPixelFormatAlpha) != 0;
}

FORCEINLINE BOOL WINGDIPAPI
GdipIsExtendedPixelFormat(GpPixelFormat pixfmt)
{
   return (pixfmt & GpPixelFormatExtended) != 0;
}

//--------------------------------------------------------------------------
// Determine if the Pixel Format is Canonical format:
//   PixelFormat32bppARGB
//   PixelFormat32bppPARGB
//   PixelFormat64bppARGB
//   PixelFormat64bppPARGB
//--------------------------------------------------------------------------

FORCEINLINE BOOL WINGDIPAPI
GdipIsCanonicalPixelFormat(GpPixelFormat pixfmt)
{
   return (pixfmt & GpPixelFormatCanonical) != 0;
}

#if (GDIPVER >= 0x0110)
//----------------------------------------------------------------------------
// Color format conversion parameters
//----------------------------------------------------------------------------

typedef enum GpPaletteType
{
    // Arbitrary custom palette provided by caller.
    GpPaletteTypeCustom           = 0,
    
    // Optimal palette generated using a median-cut algorithm.
    GpPaletteTypeOptimal        = 1,
    
    // Black and white palette.
    GpPaletteTypeFixedBW          = 2,
    
    // Symmetric halftone palettes.
    // Each of these halftone palettes will be a superset of the system palette.
    // E.g. Halftone8 will have it's 8-color on-off primaries and the 16 system
    // colors added. With duplicates removed, that leaves 16 colors.
    
    GpPaletteTypeFixedHalftone8   = 3, // 8-color, on-off primaries
    GpPaletteTypeFixedHalftone27  = 4, // 3 intensity levels of each color
    GpPaletteTypeFixedHalftone64  = 5, // 4 intensity levels of each color
    GpPaletteTypeFixedHalftone125 = 6, // 5 intensity levels of each color
    GpPaletteTypeFixedHalftone216 = 7, // 6 intensity levels of each color

    // Assymetric halftone palettes.
    // These are somewhat less useful than the symmetric ones, but are 
    // included for completeness. These do not include all of the system
    // colors.
    
    GpPaletteTypeFixedHalftone252 = 8, // 6-red, 7-green, 6-blue intensities
    GpPaletteTypeFixedHalftone256 = 9, // 8-red, 8-green, 4-blue intensities
} GpPaletteType;

typedef enum GpDitherType
{
    GpDitherTypeNone          = 0,
    
    // Solid color - picks the nearest matching color with no attempt to 
    // halftone or dither. May be used on an arbitrary palette.
    
    GpDitherTypeSolid         = 1,
    
    // Ordered dithers and spiral dithers must be used with a fixed palette.
    
    // NOTE: DitherOrdered4x4 is unique in that it may apply to 16bpp 
    // conversions also.
    
    GpDitherTypeOrdered4x4    = 2,
    
    GpDitherTypeOrdered8x8    = 3,
    GpDitherTypeOrdered16x16  = 4,
    GpDitherTypeSpiral4x4     = 5,
    GpDitherTypeSpiral8x8     = 6,
    GpDitherTypeDualSpiral4x4 = 7,
    GpDitherTypeDualSpiral8x8 = 8,
    
    // Error diffusion. May be used with any palette.
    GpDitherTypeErrorDiffusion   = 9,

    GpDitherTypeMax              = 10
} GpDitherType;
#endif //(GDIPVER >= 0x0110)

typedef enum GpPaletteFlags
{
    GpPaletteFlagsHasAlpha    = 0x0001,
    GpPaletteFlagsGrayScale   = 0x0002,
    GpPaletteFlagsHalftone    = 0x0004
} GpPaletteFlags;

typedef struct GpColorPalette
{
    UINT Flags;             // Palette flags
    UINT Count;             // Number of color entries
    ARGB Entries[1];        // Palette color entries
} GpColorPalette;

//----------------------------------------------------------------------------
// Color mode
//----------------------------------------------------------------------------

typedef enum GpColorMode
{
    GpColorModeARGB32 = 0,
    GpColorModeARGB64 = 1
} GpColorMode;

//----------------------------------------------------------------------------
// Color Channel flags
//----------------------------------------------------------------------------

typedef enum GpColorChannelFlags
{
    GpColorChannelFlagsC = 0,
    GpColorChannelFlagsM,
    GpColorChannelFlagsY,
    GpColorChannelFlagsK,
    GpColorChannelFlagsLast
} GpColorChannelFlags;

// Common color constants
typedef enum GpColorConstants
{
    GpColorAliceBlue            = 0xFFF0F8FF,
    GpColorAntiqueWhite         = 0xFFFAEBD7,
    GpColorAqua                 = 0xFF00FFFF,
    GpColorAquamarine           = 0xFF7FFFD4,
    GpColorAzure                = 0xFFF0FFFF,
    GpColorBeige                = 0xFFF5F5DC,
    GpColorBisque               = 0xFFFFE4C4,
    GpColorBlack                = 0xFF000000,
    GpColorBlanchedAlmond       = 0xFFFFEBCD,
    GpColorBlue                 = 0xFF0000FF,
    GpColorBlueViolet           = 0xFF8A2BE2,
    GpColorBrown                = 0xFFA52A2A,
    GpColorBurlyWood            = 0xFFDEB887,
    GpColorCadetBlue            = 0xFF5F9EA0,
    GpColorChartreuse           = 0xFF7FFF00,
    GpColorChocolate            = 0xFFD2691E,
    GpColorCoral                = 0xFFFF7F50,
    GpColorCornflowerBlue       = 0xFF6495ED,
    GpColorCornsilk             = 0xFFFFF8DC,
    GpColorCrimson              = 0xFFDC143C,
    GpColorCyan                 = 0xFF00FFFF,
    GpColorDarkBlue             = 0xFF00008B,
    GpColorDarkCyan             = 0xFF008B8B,
    GpColorDarkGoldenrod        = 0xFFB8860B,
    GpColorDarkGray             = 0xFFA9A9A9,
    GpColorDarkGreen            = 0xFF006400,
    GpColorDarkKhaki            = 0xFFBDB76B,
    GpColorDarkMagenta          = 0xFF8B008B,
    GpColorDarkOliveGreen       = 0xFF556B2F,
    GpColorDarkOrange           = 0xFFFF8C00,
    GpColorDarkOrchid           = 0xFF9932CC,
    GpColorDarkRed              = 0xFF8B0000,
    GpColorDarkSalmon           = 0xFFE9967A,
    GpColorDarkSeaGreen         = 0xFF8FBC8B,
    GpColorDarkSlateBlue        = 0xFF483D8B,
    GpColorDarkSlateGray        = 0xFF2F4F4F,
    GpColorDarkTurquoise        = 0xFF00CED1,
    GpColorDarkViolet           = 0xFF9400D3,
    GpColorDeepPink             = 0xFFFF1493,
    GpColorDeepSkyBlue          = 0xFF00BFFF,
    GpColorDimGray              = 0xFF696969,
    GpColorDodgerBlue           = 0xFF1E90FF,
    GpColorFirebrick            = 0xFFB22222,
    GpColorFloralWhite          = 0xFFFFFAF0,
    GpColorForestGreen          = 0xFF228B22,
    GpColorFuchsia              = 0xFFFF00FF,
    GpColorGainsboro            = 0xFFDCDCDC,
    GpColorGhostWhite           = 0xFFF8F8FF,
    GpColorGold                 = 0xFFFFD700,
    GpColorGoldenrod            = 0xFFDAA520,
    GpColorGray                 = 0xFF808080,
    GpColorGreen                = 0xFF008000,
    GpColorGreenYellow          = 0xFFADFF2F,
    GpColorHoneydew             = 0xFFF0FFF0,
    GpColorHotPink              = 0xFFFF69B4,
    GpColorIndianRed            = 0xFFCD5C5C,
    GpColorIndigo               = 0xFF4B0082,
    GpColorIvory                = 0xFFFFFFF0,
    GpColorKhaki                = 0xFFF0E68C,
    GpColorLavender             = 0xFFE6E6FA,
    GpColorLavenderBlush        = 0xFFFFF0F5,
    GpColorLawnGreen            = 0xFF7CFC00,
    GpColorLemonChiffon         = 0xFFFFFACD,
    GpColorLightBlue            = 0xFFADD8E6,
    GpColorLightCoral           = 0xFFF08080,
    GpColorLightCyan            = 0xFFE0FFFF,
    GpColorLightGoldenrodYellow = 0xFFFAFAD2,
    GpColorLightGray            = 0xFFD3D3D3,
    GpColorLightGreen           = 0xFF90EE90,
    GpColorLightPink            = 0xFFFFB6C1,
    GpColorLightSalmon          = 0xFFFFA07A,
    GpColorLightSeaGreen        = 0xFF20B2AA,
    GpColorLightSkyBlue         = 0xFF87CEFA,
    GpColorLightSlateGray       = 0xFF778899,
    GpColorLightSteelBlue       = 0xFFB0C4DE,
    GpColorLightYellow          = 0xFFFFFFE0,
    GpColorLime                 = 0xFF00FF00,
    GpColorLimeGreen            = 0xFF32CD32,
    GpColorLinen                = 0xFFFAF0E6,
    GpColorMagenta              = 0xFFFF00FF,
    GpColorMaroon               = 0xFF800000,
    GpColorMediumAquamarine     = 0xFF66CDAA,
    GpColorMediumBlue           = 0xFF0000CD,
    GpColorMediumOrchid         = 0xFFBA55D3,
    GpColorMediumPurple         = 0xFF9370DB,
    GpColorMediumSeaGreen       = 0xFF3CB371,
    GpColorMediumSlateBlue      = 0xFF7B68EE,
    GpColorMediumSpringGreen    = 0xFF00FA9A,
    GpColorMediumTurquoise      = 0xFF48D1CC,
    GpColorMediumVioletRed      = 0xFFC71585,
    GpColorMidnightBlue         = 0xFF191970,
    GpColorMintCream            = 0xFFF5FFFA,
    GpColorMistyRose            = 0xFFFFE4E1,
    GpColorMoccasin             = 0xFFFFE4B5,
    GpColorNavajoWhite          = 0xFFFFDEAD,
    GpColorNavy                 = 0xFF000080,
    GpColorOldLace              = 0xFFFDF5E6,
    GpColorOlive                = 0xFF808000,
    GpColorOliveDrab            = 0xFF6B8E23,
    GpColorOrange               = 0xFFFFA500,
    GpColorOrangeRed            = 0xFFFF4500,
    GpColorOrchid               = 0xFFDA70D6,
    GpColorPaleGoldenrod        = 0xFFEEE8AA,
    GpColorPaleGreen            = 0xFF98FB98,
    GpColorPaleTurquoise        = 0xFFAFEEEE,
    GpColorPaleVioletRed        = 0xFFDB7093,
    GpColorPapayaWhip           = 0xFFFFEFD5,
    GpColorPeachPuff            = 0xFFFFDAB9,
    GpColorPeru                 = 0xFFCD853F,
    GpColorPink                 = 0xFFFFC0CB,
    GpColorPlum                 = 0xFFDDA0DD,
    GpColorPowderBlue           = 0xFFB0E0E6,
    GpColorPurple               = 0xFF800080,
    GpColorRed                  = 0xFFFF0000,
    GpColorRosyBrown            = 0xFFBC8F8F,
    GpColorRoyalBlue            = 0xFF4169E1,
    GpColorSaddleBrown          = 0xFF8B4513,
    GpColorSalmon               = 0xFFFA8072,
    GpColorSandyBrown           = 0xFFF4A460,
    GpColorSeaGreen             = 0xFF2E8B57,
    GpColorSeaShell             = 0xFFFFF5EE,
    GpColorSienna               = 0xFFA0522D,
    GpColorSilver               = 0xFFC0C0C0,
    GpColorSkyBlue              = 0xFF87CEEB,
    GpColorSlateBlue            = 0xFF6A5ACD,
    GpColorSlateGray            = 0xFF708090,
    GpColorSnow                 = 0xFFFFFAFA,
    GpColorSpringGreen          = 0xFF00FF7F,
    GpColorSteelBlue            = 0xFF4682B4,
    GpColorTan                  = 0xFFD2B48C,
    GpColorTeal                 = 0xFF008080,
    GpColorThistle              = 0xFFD8BFD8,
    GpColorTomato               = 0xFFFF6347,
    GpColorTransparent          = 0x00FFFFFF,
    GpColorTurquoise            = 0xFF40E0D0,
    GpColorViolet               = 0xFFEE82EE,
    GpColorWheat                = 0xFFF5DEB3,
    GpColorWhite                = 0xFFFFFFFF,
    GpColorWhiteSmoke           = 0xFFF5F5F5,
    GpColorYellow               = 0xFFFFFF00,
    GpColorYellowGreen          = 0xFF9ACD32
} GpColorConstants;

// Shift count and bit mask for A, R, G, B components
typedef enum GpColorShift
{
    GpColorAlphaShift  = 24,
    GpColorRedShift    = 16,
    GpColorGreenShift  = 8,
    GpColorBlueShift   = 0
} GpColorShift;

typedef enum GpColorMask
{
    GpColorAlphaMask   = 0xff000000,
    GpColorRedMask     = 0x00ff0000,
    GpColorGreenMask   = 0x0000ff00,
    GpColorBlueMask    = 0x000000ff
} GpColorMask;

//----------------------------------------------------------------------------
// Color
//----------------------------------------------------------------------------

typedef struct GpColor
{
    union {
        struct {
            BYTE Blue;
            BYTE Green;
            BYTE Red;
            BYTE Alpha;
        };
        struct {
            BYTE B;
            BYTE G;
            BYTE R;
            BYTE A;
        };
        ARGB Argb;
        GpColorConstants Value;
    };
} GpColor;

// Assemble A, R, G, B values into a 32-bit integer
FORCEINLINE ARGB WINGDIPAPI
GdipColorMakeARGB(IN BYTE a,
                  IN BYTE r,
                  IN BYTE g,
                  IN BYTE b)
{
    return (((ARGB) (b) <<  GpColorBlueShift) |
            ((ARGB) (g) << GpColorGreenShift) |
            ((ARGB) (r) <<   GpColorRedShift) |
            ((ARGB) (a) << GpColorAlphaShift));
}

typedef struct ENHMETAHEADER3
{
    DWORD   iType;              // Record type EMR_HEADER
    DWORD   nSize;              // Record size in bytes.  This may be greater
                                // than the sizeof(ENHMETAHEADER).
    RECTL   rclBounds;          // Inclusive-inclusive bounds in device units
    RECTL   rclFrame;           // Inclusive-inclusive Picture Frame .01mm unit
    DWORD   dSignature;         // Signature.  Must be ENHMETA_SIGNATURE.
    DWORD   nVersion;           // Version number
    DWORD   nBytes;             // Size of the metafile in bytes
    DWORD   nRecords;           // Number of records in the metafile
    WORD    nHandles;           // Number of handles in the handle table
                                // Handle index zero is reserved.
    WORD    sReserved;          // Reserved.  Must be zero.
    DWORD   nDescription;       // Number of chars in the unicode desc string
                                // This is 0 if there is no description string
    DWORD   offDescription;     // Offset to the metafile description record.
                                // This is 0 if there is no description string
    DWORD   nPalEntries;        // Number of entries in the metafile palette.
    SIZEL   szlDevice;          // Size of the reference device in pels
    SIZEL   szlMillimeters;     // Size of the reference device in millimeters
} ENHMETAHEADER3;

// Placeable WMFs

// Placeable Metafiles were created as a non-standard way of specifying how 
// a metafile is mapped and scaled on an output device.
// Placeable metafiles are quite wide-spread, but not directly supported by
// the Windows API. To playback a placeable metafile using the Windows API,
// you will first need to strip the placeable metafile header from the file.
// This is typically performed by copying the metafile to a temporary file
// starting at file offset 22 (0x16). The contents of the temporary file may
// then be used as input to the Windows GetMetaFile(), PlayMetaFile(),
// CopyMetaFile(), etc. GDI functions.

// Each placeable metafile begins with a 22-byte header,
//  followed by a standard metafile:

#include <pshpack2.h>   // set structure packing to 2

typedef struct GpPWMFRect16
{
    INT16           Left;
    INT16           Top;
    INT16           Right;
    INT16           Bottom;
} GpPWMFRect16;

typedef struct GpWmfPlaceableFileHeader
{
    UINT32          Key;            // GDIP_WMF_PLACEABLEKEY
    INT16           Hmf;            // Metafile HANDLE number (always 0)
    GpPWMFRect16    BoundingBox;    // Coordinates in metafile units
    INT16           Inch;           // Number of metafile units per inch
    UINT32          Reserved;       // Reserved (always 0)
    INT16           Checksum;       // Checksum value for previous 10 WORDs
} GpWmfPlaceableFileHeader;

#include <poppack.h>

// Key contains a special identification value that indicates the presence
// of a placeable metafile header and is always 0x9AC6CDD7.

// Handle is used to stored the handle of the metafile in memory. When written
// to disk, this field is not used and will always contains the value 0.

// Left, Top, Right, and Bottom contain the coordinates of the upper-left
// and lower-right corners of the image on the output device. These are
// measured in twips.

// A twip (meaning "twentieth of a point") is the logical unit of measurement
// used in Windows Metafiles. A twip is equal to 1/1440 of an inch. Thus 720
// twips equal 1/2 inch, while 32,768 twips is 22.75 inches.

// Inch contains the number of twips per inch used to represent the image.
// Normally, there are 1440 twips per inch; however, this number may be
// changed to scale the image. A value of 720 indicates that the image is
// double its normal size, or scaled to a factor of 2:1. A value of 360
// indicates a scale of 4:1, while a value of 2880 indicates that the image
// is scaled down in size by a factor of two. A value of 1440 indicates
// a 1:1 scale ratio.

// Reserved is not used and is always set to 0.

// Checksum contains a checksum value for the previous 10 WORDs in the header.
// This value can be used in an attempt to detect if the metafile has become
// corrupted. The checksum is calculated by XORing each WORD value to an
// initial value of 0.

// If the metafile was recorded with a reference Hdc that was a display.

#define GDIP_EMFPLUSFLAGS_DISPLAY       0x00000001

typedef struct GpMetafileHeader
{
    GpMetafileType        Type;
    UINT                Size;               // Size of the metafile (in bytes)
    UINT                Version;            // EMF+, EMF, or WMF version
    UINT                EmfPlusFlags;
    REAL                DpiX;
    REAL                DpiY;
    GpRect              Bounds;             // Bounds in device units
    union
    {
        METAHEADER      WmfHeader;
        ENHMETAHEADER3  EmfHeader;
    };
    INT                 EmfPlusHeaderSize;  // size of the EMF+ header in file
    INT                 LogicalDpiX;        // Logical Dpi of reference Hdc
    INT                 LogicalDpiY;        // usually valid only for EMF+
} GpMetafileHeader;
    
// Is it any type of WMF (standard or Placeable Metafile)?
FORCEINLINE BOOL WINGDIPAPI
GdipMetafileHeaderIsWmf(const GpMetafileHeader *header)
{
    return ((header->Type == GpMetafileTypeWmf) || (header->Type == GpMetafileTypeWmfPlaceable));
}

// Is this an Placeable Metafile?
FORCEINLINE BOOL WINGDIPAPI
GdipMetafileHeaderIsWmfPlaceable(const GpMetafileHeader *header) { return (header->Type == GpMetafileTypeWmfPlaceable); }

// Is this an EMF (not an EMF+)?
FORCEINLINE BOOL WINGDIPAPI
GdipMetafileHeaderIsEmf(const GpMetafileHeader *header) { return (header->Type == GpMetafileTypeEmf); }

// Is this an EMF or EMF+ file?
FORCEINLINE BOOL WINGDIPAPI
GdipMetafileHeaderIsEmfOrEmfPlus(const GpMetafileHeader *header) { return (header->Type >= GpMetafileTypeEmf); }

// Is this an EMF+ file?
FORCEINLINE BOOL WINGDIPAPI
GdipMetafileHeaderIsEmfPlus(const GpMetafileHeader *header) { return (header->Type >= GpMetafileTypeEmfPlusOnly); }

// Is this an EMF+ dual (has dual, down-level records) file?
FORCEINLINE BOOL WINGDIPAPI
GdipMetafileHeaderIsEmfPlusDual(const GpMetafileHeader *header) { return (header->Type == GpMetafileTypeEmfPlusDual); }

// Is this an EMF+ only (no dual records) file?
FORCEINLINE BOOL WINGDIPAPI
GdipMetafileHeaderIsEmfPlusOnly(const GpMetafileHeader *header) { return (header->Type == GpMetafileTypeEmfPlusOnly); }

// If it's an EMF+ file, was it recorded against a display Hdc?
FORCEINLINE BOOL WINGDIPAPI
GdipMetafileHeaderIsDisplay(const GpMetafileHeader *header)
{
    return (GdipMetafileHeaderIsEmfPlus(header) &&
            ((header->EmfPlusFlags & GDIP_EMFPLUSFLAGS_DISPLAY) != 0));
}

//---------------------------------------------------------------------------
// Image file format identifiers
//---------------------------------------------------------------------------

DEFINE_GUID(ImageFormatUndefined, 0xb96b3ca9,0x0728,0x11d3,0x9d,0x7b,0x00,0x00,0xf8,0x1e,0xf3,0x2e);
DEFINE_GUID(ImageFormatMemoryBMP, 0xb96b3caa,0x0728,0x11d3,0x9d,0x7b,0x00,0x00,0xf8,0x1e,0xf3,0x2e);
DEFINE_GUID(ImageFormatBMP, 0xb96b3cab,0x0728,0x11d3,0x9d,0x7b,0x00,0x00,0xf8,0x1e,0xf3,0x2e);
DEFINE_GUID(ImageFormatEMF, 0xb96b3cac,0x0728,0x11d3,0x9d,0x7b,0x00,0x00,0xf8,0x1e,0xf3,0x2e);
DEFINE_GUID(ImageFormatWMF, 0xb96b3cad,0x0728,0x11d3,0x9d,0x7b,0x00,0x00,0xf8,0x1e,0xf3,0x2e);
DEFINE_GUID(ImageFormatJPEG, 0xb96b3cae,0x0728,0x11d3,0x9d,0x7b,0x00,0x00,0xf8,0x1e,0xf3,0x2e);
DEFINE_GUID(ImageFormatPNG, 0xb96b3caf,0x0728,0x11d3,0x9d,0x7b,0x00,0x00,0xf8,0x1e,0xf3,0x2e);
DEFINE_GUID(ImageFormatGIF, 0xb96b3cb0,0x0728,0x11d3,0x9d,0x7b,0x00,0x00,0xf8,0x1e,0xf3,0x2e);
DEFINE_GUID(ImageFormatTIFF, 0xb96b3cb1,0x0728,0x11d3,0x9d,0x7b,0x00,0x00,0xf8,0x1e,0xf3,0x2e);
DEFINE_GUID(ImageFormatEXIF, 0xb96b3cb2,0x0728,0x11d3,0x9d,0x7b,0x00,0x00,0xf8,0x1e,0xf3,0x2e);
DEFINE_GUID(ImageFormatIcon, 0xb96b3cb5,0x0728,0x11d3,0x9d,0x7b,0x00,0x00,0xf8,0x1e,0xf3,0x2e);

//---------------------------------------------------------------------------
// Predefined multi-frame dimension IDs
//---------------------------------------------------------------------------

DEFINE_GUID(FrameDimensionTime, 0x6aedbd6d,0x3fb5,0x418a,0x83,0xa6,0x7f,0x45,0x22,0x9d,0xc8,0x72);
DEFINE_GUID(FrameDimensionResolution, 0x84236f7b,0x3bd3,0x428f,0x8d,0xab,0x4e,0xa1,0x43,0x9c,0xa3,0x15);
DEFINE_GUID(FrameDimensionPage, 0x7462dc86,0x6180,0x4c7e,0x8e,0x3f,0xee,0x73,0x33,0xa7,0xa4,0x83);

//---------------------------------------------------------------------------
// Property sets
//---------------------------------------------------------------------------

DEFINE_GUID(FormatIDImageInformation, 0xe5836cbe,0x5eef,0x4f1d,0xac,0xde,0xae,0x4c,0x43,0xb6,0x08,0xce);
DEFINE_GUID(FormatIDJpegAppHeaders, 0x1c4afdcd,0x6177,0x43cf,0xab,0xc7,0x5f,0x51,0xaf,0x39,0xee,0x85);

//---------------------------------------------------------------------------
// Encoder parameter sets
//---------------------------------------------------------------------------

DEFINE_GUID(EncoderCompression, 0xe09d739d,0xccd4,0x44ee,0x8e,0xba,0x3f,0xbf,0x8b,0xe4,0xfc,0x58);
DEFINE_GUID(EncoderColorDepth, 0x66087055,0xad66,0x4c7c,0x9a,0x18,0x38,0xa2,0x31,0x0b,0x83,0x37);
DEFINE_GUID(EncoderScanMethod, 0x3a4e2661,0x3109,0x4e56,0x85,0x36,0x42,0xc1,0x56,0xe7,0xdc,0xfa);
DEFINE_GUID(EncoderVersion, 0x24d18c76,0x814a,0x41a4,0xbf,0x53,0x1c,0x21,0x9c,0xcc,0xf7,0x97);
DEFINE_GUID(EncoderRenderMethod, 0x6d42c53a,0x229a,0x4825,0x8b,0xb7,0x5c,0x99,0xe2,0xb9,0xa8,0xb8);
DEFINE_GUID(EncoderQuality, 0x1d5be4b5,0xfa4a,0x452d,0x9c,0xdd,0x5d,0xb3,0x51,0x05,0xe7,0xeb);
DEFINE_GUID(EncoderTransformation,0x8d0eb2d1,0xa58e,0x4ea8,0xaa,0x14,0x10,0x80,0x74,0xb7,0xb6,0xf9);
DEFINE_GUID(EncoderLuminanceTable,0xedb33bce,0x0266,0x4a77,0xb9,0x04,0x27,0x21,0x60,0x99,0xe7,0x17);
DEFINE_GUID(EncoderChrominanceTable,0xf2e455dc,0x09b3,0x4316,0x82,0x60,0x67,0x6a,0xda,0x32,0x48,0x1c);
DEFINE_GUID(EncoderSaveFlag,0x292266fc,0xac40,0x47bf,0x8c, 0xfc, 0xa8, 0x5b, 0x89, 0xa6, 0x55, 0xde);

#if (GDIPVER >= 0x0110)
DEFINE_GUID(EncoderColorSpace,0xae7a62a0,0xee2c,0x49d8,0x9d,0x7,0x1b,0xa8,0xa9,0x27,0x59,0x6e);
DEFINE_GUID(EncoderImageItems,0x63875e13,0x1f1d,0x45ab,0x91, 0x95, 0xa2, 0x9b, 0x60, 0x66, 0xa6, 0x50);
DEFINE_GUID(EncoderSaveAsCMYK,0xa219bbc9, 0xa9d, 0x4005, 0xa3, 0xee, 0x3a, 0x42, 0x1b, 0x8b, 0xb0, 0x6c);
#endif //(GDIPVER >= 0x0110)

DEFINE_GUID(CodecIImageBytes,0x025d1823,0x6c7d,0x447b,0xbb, 0xdb, 0xa3, 0xcb, 0xc3, 0xdf, 0xa2, 0xfc);

#undef INTERFACE
#define INTERFACE IImageBytes
DECLARE_INTERFACE_IID_(IImageBytes, IUnknown, "025D1823-6C7D-447B-BBDB-A3CBC3DFA2FC")
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    /*** IImageBytes methods ***/

    // Return total number of bytes in the IStream
    STDMETHOD(CountBytes)(THIS_
        OUT UINT *pcb
        ) PURE;
    
    // Locks "cb" bytes, starting from "ulOffset" in the stream, and returns the
    // pointer to the beginning of the locked memory chunk in "ppvBytes"
    STDMETHOD(LockBytes)(THIS_
        IN UINT cb,
        IN ULONG ulOffset,
        OUT const VOID ** ppvBytes
        ) PURE;

    // Unlocks "cb" bytes, pointed by "pvBytes", starting from "ulOffset" in the
    // stream
    STDMETHOD(UnlockBytes)(THIS_
        IN const VOID *pvBytes,
        IN UINT cb,
        IN ULONG ulOffset
        ) PURE;
};

#if !defined(__cplusplus) || defined(CINTERFACE)
#define IImageBytes_QueryInterface(p,a,b)        (p)->lpVtbl->QueryInterface(p,a,b)
#define IImageBytes_AddRef(p)                    (p)->lpVtbl->AddRef(p)
#define IImageBytes_Release(p)                   (p)->lpVtbl->Release(p)
#define IImageBytes_CountBytes(p,a)              (p)->lpVtbl->CountBytes(p,a)
#define IImageBytes_LockBytes(p,a,b,c)           (p)->lpVtbl->LockBytes(p,a,b,c)
#define IImageBytes_UnlockBytes(p,a,b,c)         (p)->lpVtbl->UnlockBytes(p,a,b,c)
#else
#define IImageBytes_QueryInterface(p,a,b)        (p)->QueryInterface(a,b)
#define IImageBytes_AddRef(p)                    (p)->AddRef()
#define IImageBytes_Release(p)                   (p)->Release()
#define IImageBytes_CountBytes(p,a)              (p)->CountBytes(a)
#define IImageBytes_LockBytes(p,a,b,c)           (p)->LockBytes(a,b,c)
#define IImageBytes_UnlockBytes(p,a,b,c)         (p)->UnlockBytes(a,b,c)
#endif

//--------------------------------------------------------------------------
// ImageCodecInfo structure
//--------------------------------------------------------------------------

typedef struct GpImageCodecInfo
{
    CLSID Clsid;
    GUID  FormatID;
    const WCHAR* CodecName;
    const WCHAR* DllName;
    const WCHAR* FormatDescription;
    const WCHAR* FilenameExtension;
    const WCHAR* MimeType;
    DWORD Flags;
    DWORD Version;
    DWORD SigCount;
    DWORD SigSize;
    const BYTE* SigPattern;
    const BYTE* SigMask;
} GpImageCodecInfo;

//--------------------------------------------------------------------------
// Information flags about image codecs
//--------------------------------------------------------------------------

typedef enum GpImageCodecFlags
{
    GpImageCodecFlagsEncoder            = 0x00000001,
    GpImageCodecFlagsDecoder            = 0x00000002,
    GpImageCodecFlagsSupportBitmap      = 0x00000004,
    GpImageCodecFlagsSupportVector      = 0x00000008,
    GpImageCodecFlagsSeekableEncode     = 0x00000010,
    GpImageCodecFlagsBlockingDecode     = 0x00000020,

    GpImageCodecFlagsBuiltin            = 0x00010000,
    GpImageCodecFlagsSystem             = 0x00020000,
    GpImageCodecFlagsUser               = 0x00040000
} GpImageCodecFlags;

//---------------------------------------------------------------------------
// Access modes used when calling Image::LockBits
//---------------------------------------------------------------------------

typedef enum GpImageLockMode
{
    GpImageLockModeRead        = 0x0001,
    GpImageLockModeWrite       = 0x0002,
    GpImageLockModeUserInputBuf= 0x0004
} GpImageLockMode;

//---------------------------------------------------------------------------
// Information about image pixel data
//---------------------------------------------------------------------------

typedef struct GpBitmapData
{
    UINT Width;
    UINT Height;
    INT Stride;
    GpPixelFormat PixelFormat;
    VOID* Scan0;
    UINT_PTR Reserved;
} GpBitmapData;

//---------------------------------------------------------------------------
// Image flags
//---------------------------------------------------------------------------

typedef enum GpImageFlags
{
    GpImageFlagsNone                = 0,

    // Low-word: shared with SINKFLAG_x

    GpImageFlagsScalable            = 0x0001,
    GpImageFlagsHasAlpha            = 0x0002,
    GpImageFlagsHasTranslucent      = 0x0004,
    GpImageFlagsPartiallyScalable   = 0x0008,

    // Low-word: color space definition

    GpImageFlagsColorSpaceRGB       = 0x0010,
    GpImageFlagsColorSpaceCMYK      = 0x0020,
    GpImageFlagsColorSpaceGRAY      = 0x0040,
    GpImageFlagsColorSpaceYCBCR     = 0x0080,
    GpImageFlagsColorSpaceYCCK      = 0x0100,
 
    // Low-word: image size info

    GpImageFlagsHasRealDPI          = 0x1000,
    GpImageFlagsHasRealPixelSize    = 0x2000,

    // High-word

    GpImageFlagsReadOnly            = 0x00010000,
    GpImageFlagsCaching             = 0x00020000
} GpImageFlags;

typedef enum GpRotateFlipType
{
    GpRotateNoneFlipNone = 0,
    GpRotate90FlipNone   = 1,
    GpRotate180FlipNone  = 2,
    GpRotate270FlipNone  = 3,

    GpRotateNoneFlipX    = 4,
    GpRotate90FlipX      = 5,
    GpRotate180FlipX     = 6,
    GpRotate270FlipX     = 7,

    GpRotateNoneFlipY    = GpRotate180FlipX,
    GpRotate90FlipY      = GpRotate270FlipX,
    GpRotate180FlipY     = GpRotateNoneFlipX,
    GpRotate270FlipY     = GpRotate90FlipX,

    GpRotateNoneFlipXY   = GpRotate180FlipNone,
    GpRotate90FlipXY     = GpRotate270FlipNone,
    GpRotate180FlipXY    = GpRotateNoneFlipNone,
    GpRotate270FlipXY    = GpRotate90FlipNone
} GpRotateFlipType;

//---------------------------------------------------------------------------
// Encoder Parameter structure
//---------------------------------------------------------------------------
typedef struct GpEncoderParameter
{
    GUID    Guid;               // GUID of the parameter
    ULONG   NumberOfValues;     // Number of the parameter values
    ULONG   Type;               // Value type, like ValueTypeLONG  etc.
    VOID*   Value;              // A pointer to the parameter values
} GpEncoderParameter;

//---------------------------------------------------------------------------
// Encoder Parameters structure
//---------------------------------------------------------------------------
typedef struct GpEncoderParameters
{
    UINT Count;                      // Number of parameters in this structure
    GpEncoderParameter Parameter[1];   // Parameter values
} GpEncoderParameters;

#if (GDIPVER >= 0x0110)
typedef enum GpItemDataPosition
{
    GpItemDataPositionAfterHeader    = 0x0,
    GpItemDataPositionAfterPalette   = 0x1,
    GpItemDataPositionAfterBits      = 0x2,
} GpItemDataPosition;

//---------------------------------------------------------------------------
// External Data Item
//---------------------------------------------------------------------------
typedef struct GpImageItemData
{
    UINT  Size;           // size of the structure 
    UINT  Position;       // flags describing how the data is to be used.
    VOID *Desc;           // description on how the data is to be saved.
                          // it is different for every codec type.
    UINT  DescSize;       // size memory pointed by Desc
    VOID *Data;           // pointer to the data that is to be saved in the
                          // file, could be anything saved directly.
    UINT  DataSize;       // size memory pointed by Data
    UINT  Cookie;         // opaque for the apps data member used during
                          // enumeration of image data items.
} GpImageItemData;
#endif //(GDIPVER >= 0x0110)

//---------------------------------------------------------------------------
// Property Item
//---------------------------------------------------------------------------
typedef struct GpPropertyItem
{
    PROPID  id;                 // ID of this property
    ULONG   length;             // Length of the property value, in bytes
    WORD    type;               // Type of the value, as one of TAG_TYPE_XXX
                                // defined above
    VOID*   value;              // property value
} GpPropertyItem;

//---------------------------------------------------------------------------
// Image property types 
//---------------------------------------------------------------------------
typedef enum GpPropertyTagType
{
    GpPropertyTagTypeByte       =  1,
    GpPropertyTagTypeASCII      =  2,
    GpPropertyTagTypeShort      =  3,
    GpPropertyTagTypeLong       =  4,
    GpPropertyTagTypeRational   =  5,
    GpPropertyTagTypeUndefined  =  7,
    GpPropertyTagTypeSLONG      =  9,
    GpPropertyTagTypeSRational  = 10,
} GpPropertyTagType;

//---------------------------------------------------------------------------
// Image property ID tags
//---------------------------------------------------------------------------
typedef enum GpPropertyTag
{
    GpPropertyTagExifIFD            = 0x8769,
    GpPropertyTagGpsIFD             = 0x8825,

    GpPropertyTagNewSubfileType     = 0x00FE,
    GpPropertyTagSubfileType        = 0x00FF,
    GpPropertyTagImageWidth         = 0x0100,
    GpPropertyTagImageHeight        = 0x0101,
    GpPropertyTagBitsPerSample      = 0x0102,
    GpPropertyTagCompression        = 0x0103,
    GpPropertyTagPhotometricInterp  = 0x0106,
    GpPropertyTagThreshHolding      = 0x0107,
    GpPropertyTagCellWidth          = 0x0108,
    GpPropertyTagCellHeight         = 0x0109,
    GpPropertyTagFillOrder          = 0x010A,
    GpPropertyTagDocumentName       = 0x010D,
    GpPropertyTagImageDescription   = 0x010E,
    GpPropertyTagEquipMake          = 0x010F,
    GpPropertyTagEquipModel         = 0x0110,
    GpPropertyTagStripOffsets       = 0x0111,
    GpPropertyTagOrientation        = 0x0112,
    GpPropertyTagSamplesPerPixel    = 0x0115,
    GpPropertyTagRowsPerStrip       = 0x0116,
    GpPropertyTagStripBytesCount    = 0x0117,
    GpPropertyTagMinSampleValue     = 0x0118,
    GpPropertyTagMaxSampleValue     = 0x0119,
    GpPropertyTagXResolution        = 0x011A,   // Image resolution in width direction
    GpPropertyTagYResolution        = 0x011B,   // Image resolution in height direction
    GpPropertyTagPlanarConfig       = 0x011C,   // Image data arrangement
    GpPropertyTagPageName           = 0x011D,
    GpPropertyTagXPosition          = 0x011E,
    GpPropertyTagYPosition          = 0x011F,
    GpPropertyTagFreeOffset         = 0x0120,
    GpPropertyTagFreeByteCounts     = 0x0121,
    GpPropertyTagGrayResponseUnit   = 0x0122,
    GpPropertyTagGrayResponseCurve  = 0x0123,
    GpPropertyTagT4Option           = 0x0124,
    GpPropertyTagT6Option           = 0x0125,
    GpPropertyTagResolutionUnit     = 0x0128,   // Unit of X and Y resolution
    GpPropertyTagPageNumber         = 0x0129,
    GpPropertyTagTransferFuncition  = 0x012D,
    GpPropertyTagSoftwareUsed       = 0x0131,
    GpPropertyTagDateTime           = 0x0132,
    GpPropertyTagArtist             = 0x013B,
    GpPropertyTagHostComputer       = 0x013C,
    GpPropertyTagPredictor          = 0x013D,
    GpPropertyTagWhitePoint         = 0x013E,
    GpPropertyTagPrimaryChromaticities  = 0x013F,
    GpPropertyTagColorMap           = 0x0140,
    GpPropertyTagHalftoneHints      = 0x0141,
    GpPropertyTagTileWidth          = 0x0142,
    GpPropertyTagTileLength         = 0x0143,
    GpPropertyTagTileOffset         = 0x0144,
    GpPropertyTagTileByteCounts     = 0x0145,
    GpPropertyTagInkSet             = 0x014C,
    GpPropertyTagInkNames           = 0x014D,
    GpPropertyTagNumberOfInks       = 0x014E,
    GpPropertyTagDotRange           = 0x0150,
    GpPropertyTagTargetPrinter      = 0x0151,
    GpPropertyTagExtraSamples       = 0x0152,
    GpPropertyTagSampleFormat       = 0x0153,
    GpPropertyTagSMinSampleValue    = 0x0154,
    GpPropertyTagSMaxSampleValue    = 0x0155,
    GpPropertyTagTransferRange      = 0x0156,

    GpPropertyTagJPEGProc           = 0x0200,
    GpPropertyTagJPEGInterFormat    = 0x0201,
    GpPropertyTagJPEGInterLength    = 0x0202,
    GpPropertyTagJPEGRestartInterval    = 0x0203,
    GpPropertyTagJPEGLosslessPredictors = 0x0205,
    GpPropertyTagJPEGPointTransforms    = 0x0206,
    GpPropertyTagJPEGQTables        = 0x0207,
    GpPropertyTagJPEGDCTables       = 0x0208,
    GpPropertyTagJPEGACTables       = 0x0209,

    GpPropertyTagYCbCrCoefficients  = 0x0211,
    GpPropertyTagYCbCrSubsampling   = 0x0212,
    GpPropertyTagYCbCrPositioning   = 0x0213,
    GpPropertyTagREFBlackWhite      = 0x0214,

    GpPropertyTagICCProfile         = 0x8773,   // This TAG is defined by ICC
                                                // for embedded ICC in TIFF
    GpPropertyTagGamma              = 0x0301,
    GpPropertyTagICCProfileDescriptor   = 0x0302,
    GpPropertyTagSRGBRenderingIntent    = 0x0303,

    GpPropertyTagImageTitle         = 0x0320,
    GpPropertyTagCopyright          = 0x8298,

// Extra TAGs (Like Adobe Image Information tags etc.)

    GpPropertyTagResolutionXUnit            = 0x5001,
    GpPropertyTagResolutionYUnit            = 0x5002,
    GpPropertyTagResolutionXLengthUnit      = 0x5003,
    GpPropertyTagResolutionYLengthUnit      = 0x5004,
    GpPropertyTagPrintFlags                 = 0x5005,
    GpPropertyTagPrintFlagsVersion          = 0x5006,
    GpPropertyTagPrintFlagsCrop             = 0x5007,
    GpPropertyTagPrintFlagsBleedWidth       = 0x5008,
    GpPropertyTagPrintFlagsBleedWidthScale  = 0x5009,
    GpPropertyTagHalftoneLPI                = 0x500A,
    GpPropertyTagHalftoneLPIUnit            = 0x500B,
    GpPropertyTagHalftoneDegree             = 0x500C,
    GpPropertyTagHalftoneShape              = 0x500D,
    GpPropertyTagHalftoneMisc               = 0x500E,
    GpPropertyTagHalftoneScreen             = 0x500F,
    GpPropertyTagJPEGQuality                = 0x5010,
    GpPropertyTagGridSize                   = 0x5011,
    GpPropertyTagThumbnailFormat            = 0x5012,  // 1 = JPEG, 0 = RAW RGB
    GpPropertyTagThumbnailWidth             = 0x5013,
    GpPropertyTagThumbnailHeight            = 0x5014,
    GpPropertyTagThumbnailColorDepth        = 0x5015,
    GpPropertyTagThumbnailPlanes            = 0x5016,
    GpPropertyTagThumbnailRawBytes          = 0x5017,
    GpPropertyTagThumbnailSize              = 0x5018,
    GpPropertyTagThumbnailCompressedSize    = 0x5019,
    GpPropertyTagColorTransferFunction      = 0x501A,
    GpPropertyTagThumbnailData              = 0x501B,// RAW thumbnail bits in
                                                     // JPEG format or RGB format
                                                     // depends on
                                                     // PropertyTagThumbnailFormat

// Thumbnail related TAGs
                                                
    GpPropertyTagThumbnailImageWidth        = 0x5020,  // Thumbnail width
    GpPropertyTagThumbnailImageHeight       = 0x5021,  // Thumbnail height
    GpPropertyTagThumbnailBitsPerSample     = 0x5022,  // Number of bits per
                                                       // component
    GpPropertyTagThumbnailCompression       = 0x5023,  // Compression Scheme
    GpPropertyTagThumbnailPhotometricInterp = 0x5024,  // Pixel composition
    GpPropertyTagThumbnailImageDescription  = 0x5025,  // Image Tile
    GpPropertyTagThumbnailEquipMake         = 0x5026,  // Manufacturer of Image
                                                       // Input equipment
    GpPropertyTagThumbnailEquipModel        = 0x5027,  // Model of Image input
                                                       // equipment
    GpPropertyTagThumbnailStripOffsets      = 0x5028,  // Image data location
    GpPropertyTagThumbnailOrientation       = 0x5029,  // Orientation of image
    GpPropertyTagThumbnailSamplesPerPixel   = 0x502A,  // Number of components
    GpPropertyTagThumbnailRowsPerStrip      = 0x502B,  // Number of rows per strip
    GpPropertyTagThumbnailStripBytesCount   = 0x502C,  // Bytes per compressed
                                                       // strip
    GpPropertyTagThumbnailResolutionX       = 0x502D,  // Resolution in width
                                                       // direction
    GpPropertyTagThumbnailResolutionY       = 0x502E,  // Resolution in height
                                                       // direction
    GpPropertyTagThumbnailPlanarConfig      = 0x502F,  // Image data arrangement
    GpPropertyTagThumbnailResolutionUnit    = 0x5030,  // Unit of X and Y
                                                       // Resolution
    GpPropertyTagThumbnailTransferFunction  = 0x5031,  // Transfer function
    GpPropertyTagThumbnailSoftwareUsed      = 0x5032,  // Software used
    GpPropertyTagThumbnailDateTime          = 0x5033,  // File change date and
                                                       // time
    GpPropertyTagThumbnailArtist            = 0x5034,  // Person who created the
                                                       // image
    GpPropertyTagThumbnailWhitePoint        = 0x5035,  // White point chromaticity
    GpPropertyTagThumbnailPrimaryChromaticities  = 0x5036, 
                                                       // Chromaticities of
                                                       // primaries
    GpPropertyTagThumbnailYCbCrCoefficients = 0x5037,  // Color space transforma-
                                                       // tion coefficients
    GpPropertyTagThumbnailYCbCrSubsampling  = 0x5038,  // Subsampling ratio of Y
                                                       // to C
    GpPropertyTagThumbnailYCbCrPositioning  = 0x5039,  // Y and C position
    GpPropertyTagThumbnailRefBlackWhite     = 0x503A,  // Pair of black and white
                                                       // reference values
    GpPropertyTagThumbnailCopyRight         = 0x503B,  // CopyRight holder

    GpPropertyTagLuminanceTable             = 0x5090,
    GpPropertyTagChrominanceTable           = 0x5091,

    GpPropertyTagFrameDelay                 = 0x5100,
    GpPropertyTagLoopCount                  = 0x5101,

#if (GDIPVER >= 0x0110)
    GpPropertyTagGlobalPalette              = 0x5102,
    GpPropertyTagIndexBackground            = 0x5103,
    GpPropertyTagIndexTransparent           = 0x5104,
#endif //(GDIPVER >= 0x0110)

    GpPropertyTagPixelUnit          = 0x5110,  // Unit specifier for pixel/unit
    GpPropertyTagPixelPerUnitX      = 0x5111,  // Pixels per unit in X
    GpPropertyTagPixelPerUnitY      = 0x5112,  // Pixels per unit in Y
    GpPropertyTagPaletteHistogram   = 0x5113,  // Palette histogram

// EXIF specific tag

    GpPropertyTagExifExposureTime   = 0x829A,
    GpPropertyTagExifFNumber        = 0x829D,

    GpPropertyTagExifExposureProg   = 0x8822,
    GpPropertyTagExifSpectralSense  = 0x8824,
    GpPropertyTagExifISOSpeed       = 0x8827,
    GpPropertyTagExifOECF           = 0x8828,

    GpPropertyTagExifVer             = 0x9000,
    GpPropertyTagExifDTOrig          = 0x9003, // Date & time of original
    GpPropertyTagExifDTDigitized     = 0x9004, // Date & time of digital data generation

    GpPropertyTagExifCompConfig      = 0x9101,
    GpPropertyTagExifCompBPP         = 0x9102,

    GpPropertyTagExifShutterSpeed    = 0x9201,
    GpPropertyTagExifAperture        = 0x9202,
    GpPropertyTagExifBrightness      = 0x9203,
    GpPropertyTagExifExposureBias    = 0x9204,
    GpPropertyTagExifMaxAperture     = 0x9205,
    GpPropertyTagExifSubjectDist     = 0x9206,
    GpPropertyTagExifMeteringMode    = 0x9207,
    GpPropertyTagExifLightSource     = 0x9208,
    GpPropertyTagExifFlash           = 0x9209,
    GpPropertyTagExifFocalLength     = 0x920A,
    GpPropertyTagExifSubjectArea     = 0x9214,  // exif 2.2 Subject Area
    GpPropertyTagExifMakerNote       = 0x927C,
    GpPropertyTagExifUserComment     = 0x9286,
    GpPropertyTagExifDTSubsec        = 0x9290,  // Date & Time subseconds
    GpPropertyTagExifDTOrigSS        = 0x9291,  // Date & Time original subseconds
    GpPropertyTagExifDTDigSS         = 0x9292,  // Date & TIme digitized subseconds

    GpPropertyTagExifFPXVer          = 0xA000,
    GpPropertyTagExifColorSpace      = 0xA001,
    GpPropertyTagExifPixXDim         = 0xA002,
    GpPropertyTagExifPixYDim         = 0xA003,
    GpPropertyTagExifRelatedWav      = 0xA004,  // related sound file
    GpPropertyTagExifInterop         = 0xA005,
    GpPropertyTagExifFlashEnergy     = 0xA20B,
    GpPropertyTagExifSpatialFR       = 0xA20C,  // Spatial Frequency Response
    GpPropertyTagExifFocalXRes       = 0xA20E,  // Focal Plane X Resolution
    GpPropertyTagExifFocalYRes       = 0xA20F,  // Focal Plane Y Resolution
    GpPropertyTagExifFocalResUnit    = 0xA210,  // Focal Plane Resolution Unit
    GpPropertyTagExifSubjectLoc      = 0xA214,
    GpPropertyTagExifExposureIndex   = 0xA215,
    GpPropertyTagExifSensingMethod   = 0xA217,
    GpPropertyTagExifFileSource      = 0xA300,
    GpPropertyTagExifSceneType       = 0xA301,
    GpPropertyTagExifCfaPattern      = 0xA302,

// New EXIF 2.2 properties

    GpPropertyTagExifCustomRendered         = 0xA401,
    GpPropertyTagExifExposureMode           = 0xA402,
    GpPropertyTagExifWhiteBalance           = 0xA403,
    GpPropertyTagExifDigitalZoomRatio       = 0xA404,
    GpPropertyTagExifFocalLengthIn35mmFilm  = 0xA405,
    GpPropertyTagExifSceneCaptureType       = 0xA406,
    GpPropertyTagExifGainControl            = 0xA407,
    GpPropertyTagExifContrast               = 0xA408,
    GpPropertyTagExifSaturation             = 0xA409,
    GpPropertyTagExifSharpness              = 0xA40A,
    GpPropertyTagExifDeviceSettingDesc      = 0xA40B,
    GpPropertyTagExifSubjectDistanceRange   = 0xA40C,
    GpPropertyTagExifUniqueImageID          = 0xA420,


    GpPropertyTagGpsVer             = 0x0000,
    GpPropertyTagGpsLatitudeRef     = 0x0001,
    GpPropertyTagGpsLatitude        = 0x0002,
    GpPropertyTagGpsLongitudeRef    = 0x0003,
    GpPropertyTagGpsLongitude       = 0x0004,
    GpPropertyTagGpsAltitudeRef     = 0x0005,
    GpPropertyTagGpsAltitude        = 0x0006,
    GpPropertyTagGpsGpsTime         = 0x0007,
    GpPropertyTagGpsGpsSatellites   = 0x0008,
    GpPropertyTagGpsGpsStatus       = 0x0009,
    GpPropertyTagGpsGpsMeasureMode  = 0x00A,
    GpPropertyTagGpsGpsDop          = 0x000B,  // Measurement precision
    GpPropertyTagGpsSpeedRef        = 0x000C,
    GpPropertyTagGpsSpeed           = 0x000D,
    GpPropertyTagGpsTrackRef        = 0x000E,
    GpPropertyTagGpsTrack           = 0x000F,
    GpPropertyTagGpsImgDirRef       = 0x0010,
    GpPropertyTagGpsImgDir          = 0x0011,
    GpPropertyTagGpsMapDatum        = 0x0012,
    GpPropertyTagGpsDestLatRef      = 0x0013,
    GpPropertyTagGpsDestLat         = 0x0014,
    GpPropertyTagGpsDestLongRef     = 0x0015,
    GpPropertyTagGpsDestLong        = 0x0016,
    GpPropertyTagGpsDestBearRef     = 0x0017,
    GpPropertyTagGpsDestBear        = 0x0018,
    GpPropertyTagGpsDestDistRef     = 0x0019,
    GpPropertyTagGpsDestDist        = 0x001A,
    GpPropertyTagGpsProcessingMethod   = 0x001B,
    GpPropertyTagGpsAreaInformation = 0x001C,
    GpPropertyTagGpsDate            = 0x001D,
    GpPropertyTagGpsDifferential    = 0x001E,
} GpPropertyTag;

#if (GDIPVER >= 0x0110)
//----------------------------------------------------------------------------
// Color channel look up table (LUT)
//----------------------------------------------------------------------------

typedef BYTE GpColorChannelLUT[256];

//----------------------------------------------------------------------------
// Per-channel Histogram for 8bpp images.
//----------------------------------------------------------------------------

typedef enum GpHistogramFormat
{
    GpHistogramFormatARGB,
    GpHistogramFormatPARGB,
    GpHistogramFormatRGB,
    GpHistogramFormatGray,
    GpHistogramFormatB,
    GpHistogramFormatG,
    GpHistogramFormatR,
    GpHistogramFormatA    
} GpHistogramFormat;
#endif //(GDIPVER >= 0x0110)

//----------------------------------------------------------------------------
// Color matrix
//----------------------------------------------------------------------------

typedef struct GpColorMatrix
{
    REAL m[5][5];
} GpColorMatrix;

//----------------------------------------------------------------------------
// Color Matrix flags
//----------------------------------------------------------------------------

typedef enum GpColorMatrixFlags
{
    GpColorMatrixFlagsDefault   = 0,
    GpColorMatrixFlagsSkipGrays = 1,
    GpColorMatrixFlagsAltGray   = 2
} GpColorMatrixFlags;

//----------------------------------------------------------------------------
// Color Adjust Type
//----------------------------------------------------------------------------

typedef enum GpColorAdjustType
{
    GpColorAdjustTypeDefault,
    GpColorAdjustTypeBitmap,
    GpColorAdjustTypeBrush,
    GpColorAdjustTypePen,
    GpColorAdjustTypeText,
    GpColorAdjustTypeCount,
    GpColorAdjustTypeAny      // Reserved
} GpColorAdjustType;

//----------------------------------------------------------------------------
// Color Map
//----------------------------------------------------------------------------

typedef struct GpColorMap
{
    GpColor oldColor;
    GpColor newColor;
} GpColorMap;

//---------------------------------------------------------------------------
// Raw GDI+ classes for internal type checking
//---------------------------------------------------------------------------

#ifdef __cplusplus
#define RAWGDIP_BASECLASSES(Name) struct Name { private: Name(const Name &); virtual ~Name() = 0; }
#define RAWGDIP_CLASSES(Name, Base) struct Name Base { private: Name(const Name &); virtual ~Name() = 0; }
#else
#define RAWGDIP_BASECLASSES(Name) typedef void Name
#define RAWGDIP_CLASSES(Name, Base) typedef struct Name Name
#endif

RAWGDIP_CLASSES(GpGraphics,);
RAWGDIP_CLASSES(GpMatrix,);

RAWGDIP_BASECLASSES(GpBrush);
RAWGDIP_CLASSES(GpTexture, : GpBrush);
RAWGDIP_CLASSES(GpSolidFill, : GpBrush);
RAWGDIP_CLASSES(GpLineGradient, : GpBrush);
RAWGDIP_CLASSES(GpPathGradient, : GpBrush);
RAWGDIP_CLASSES(GpHatch, : GpBrush);

RAWGDIP_CLASSES(GpPen,);
RAWGDIP_BASECLASSES(GpCustomLineCap);
RAWGDIP_CLASSES(GpAdjustableArrowCap, : GpCustomLineCap);

RAWGDIP_BASECLASSES(GpImage);
RAWGDIP_CLASSES(GpBitmap, : GpImage);
RAWGDIP_CLASSES(GpMetafile, : GpImage);
RAWGDIP_CLASSES(GpImageAttributes,);

RAWGDIP_CLASSES(GpPath,);
RAWGDIP_CLASSES(GpRegion,);
RAWGDIP_CLASSES(GpPathIterator,);

RAWGDIP_CLASSES(GpFontFamily,);
RAWGDIP_CLASSES(GpFont,);
RAWGDIP_CLASSES(GpStringFormat,);
RAWGDIP_BASECLASSES(GpFontCollection);
RAWGDIP_CLASSES(GpInstalledFontCollection, : GpFontCollection);
RAWGDIP_CLASSES(GpPrivateFontCollection, : GpFontCollection);

RAWGDIP_CLASSES(GpCachedBitmap,);

#if (GDIPVER >= 0x0110)

//-----------------------------------------------------------------------------
// GDI+ effect GUIDs
//-----------------------------------------------------------------------------

// {633C80A4-1843-482b-9EF2-BE2834C5FDD4}
static const GUID BlurEffectGuid = 
{ 0x633c80a4, 0x1843, 0x482b, { 0x9e, 0xf2, 0xbe, 0x28, 0x34, 0xc5, 0xfd, 0xd4 } };

// {63CBF3EE-C526-402c-8F71-62C540BF5142}
static const GUID SharpenEffectGuid = 
{ 0x63cbf3ee, 0xc526, 0x402c, { 0x8f, 0x71, 0x62, 0xc5, 0x40, 0xbf, 0x51, 0x42 } };

// {718F2615-7933-40e3-A511-5F68FE14DD74}
static const GUID ColorMatrixEffectGuid = 
{ 0x718f2615, 0x7933, 0x40e3, { 0xa5, 0x11, 0x5f, 0x68, 0xfe, 0x14, 0xdd, 0x74 } };

// {A7CE72A9-0F7F-40d7-B3CC-D0C02D5C3212}
static const GUID ColorLUTEffectGuid = 
{ 0xa7ce72a9, 0xf7f, 0x40d7, { 0xb3, 0xcc, 0xd0, 0xc0, 0x2d, 0x5c, 0x32, 0x12 } };

// {D3A1DBE1-8EC4-4c17-9F4C-EA97AD1C343D}
static const GUID BrightnessContrastEffectGuid = 
{ 0xd3a1dbe1, 0x8ec4, 0x4c17, { 0x9f, 0x4c, 0xea, 0x97, 0xad, 0x1c, 0x34, 0x3d } };

// {8B2DD6C3-EB07-4d87-A5F0-7108E26A9C5F}
static const GUID HueSaturationLightnessEffectGuid = 
{ 0x8b2dd6c3, 0xeb07, 0x4d87, { 0xa5, 0xf0, 0x71, 0x8, 0xe2, 0x6a, 0x9c, 0x5f } };

// {99C354EC-2A31-4f3a-8C34-17A803B33A25}
static const GUID LevelsEffectGuid = 
{ 0x99c354ec, 0x2a31, 0x4f3a, { 0x8c, 0x34, 0x17, 0xa8, 0x3, 0xb3, 0x3a, 0x25 } };

// {1077AF00-2848-4441-9489-44AD4C2D7A2C}
static const GUID TintEffectGuid = 
{ 0x1077af00, 0x2848, 0x4441, { 0x94, 0x89, 0x44, 0xad, 0x4c, 0x2d, 0x7a, 0x2c } };

// {537E597D-251E-48da-9664-29CA496B70F8}
static const GUID ColorBalanceEffectGuid = 
{ 0x537e597d, 0x251e, 0x48da, { 0x96, 0x64, 0x29, 0xca, 0x49, 0x6b, 0x70, 0xf8 } };

// {74D29D05-69A4-4266-9549-3CC52836B632}
static const GUID RedEyeCorrectionEffectGuid = 
{ 0x74d29d05, 0x69a4, 0x4266, { 0x95, 0x49, 0x3c, 0xc5, 0x28, 0x36, 0xb6, 0x32 } };

// {DD6A0022-58E4-4a67-9D9B-D48EB881A53D}
static const GUID ColorCurveEffectGuid =
{ 0xdd6a0022, 0x58e4, 0x4a67, { 0x9d, 0x9b, 0xd4, 0x8e, 0xb8, 0x81, 0xa5, 0x3d }
 };

//-----------------------------------------------------------------------------

typedef struct GpSharpenParams
{
    float radius;
    float amount;
} GpSharpenParams;

typedef struct GpBlurParams
{
    float radius;
    BOOL expandEdge;
} GpBlurParams;

typedef struct GpBrightnessContrastParams
{
    INT brightnessLevel;
    INT contrastLevel;
} GpBrightnessContrastParams;

typedef struct GpRedEyeCorrectionParams
{
    UINT numberOfAreas;
    RECT *areas;
} GpRedEyeCorrectionParams;

typedef struct GpHueSaturationLightnessParams
{
    INT hueLevel;
    INT saturationLevel;
    INT lightnessLevel;
} GpHueSaturationLightnessParams;

typedef struct GpTintParams
{
    INT hue;
    INT amount;
} GpTintParams;

typedef struct GpLevelsParams
{
    INT highlight;
    INT midtone;
    INT shadow;
} GpLevelsParams;

typedef struct GpColorBalanceParams
{
    INT cyanRed;
    INT magentaGreen;
    INT yellowBlue;
} GpColorBalanceParams;

typedef struct GpColorLUTParams
{
    // look up tables for each color channel.
    
    GpColorChannelLUT lutB;
    GpColorChannelLUT lutG;
    GpColorChannelLUT lutR;
    GpColorChannelLUT lutA;
} GpColorLUTParams;

typedef enum GpCurveAdjustments
{
    GpAdjustExposure,
    GpAdjustDensity,
    GpAdjustContrast,
    GpAdjustHighlight,
    GpAdjustShadow,
    GpAdjustMidtone,
    GpAdjustWhiteSaturation,
    GpAdjustBlackSaturation
} GpCurveAdjustments;

typedef enum GpCurveChannel
{
    GpCurveChannelAll,
    GpCurveChannelRed,
    GpCurveChannelGreen,
    GpCurveChannelBlue
} GpCurveChannel;

typedef struct GpColorCurveParams
{
    GpCurveAdjustments adjustment;
    GpCurveChannel channel;
    INT adjustValue;
} GpColorCurveParams;

RAWGDIP_CLASSES(GpEffect, );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateEffect(const GUID guid, GpEffect **effect);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDeleteEffect(GpEffect *effect);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetEffectParameterSize(GpEffect *effect, UINT *size);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetEffectParameters(GpEffect *effect, const VOID *params, const UINT size);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetEffectParameters(GpEffect *effect, UINT *size, VOID *params);

#endif //(GDIPVER >= 0x0110)

//----------------------------------------------------------------------------
// GraphicsPath APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreatePath(GpFillMode brushMode, GpPath **path);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreatePath2(GDIPCONST GpPointF*, GDIPCONST BYTE*, INT, GpFillMode,
                                    GpPath **path);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreatePath2I(GDIPCONST GpPoint*, GDIPCONST BYTE*, INT, GpFillMode,
                                     GpPath **path);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipClonePath(GpPath* path, GpPath **clonePath);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDeletePath(GpPath* path);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipResetPath(GpPath* path);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPointCount(GpPath* path, INT* count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathTypes(GpPath* path, BYTE* types, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathPoints(GpPath*, GpPointF* points, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathPointsI(GpPath*, GpPoint* points, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathFillMode(GpPath *path, GpFillMode *fillmode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPathFillMode(GpPath *path, GpFillMode fillmode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathData(GpPath *path, GpPathData* pathData);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipStartPathFigure(GpPath *path);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipClosePathFigure(GpPath *path);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipClosePathFigures(GpPath *path);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPathMarker(GpPath* path);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipClearPathMarkers(GpPath* path);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipReversePath(GpPath* path);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathLastPoint(GpPath* path, GpPointF* lastPoint);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathLine(GpPath *path, REAL x1, REAL y1, REAL x2, REAL y2);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathLine2(GpPath *path, GDIPCONST GpPointF *points, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathArc(GpPath *path, REAL x, REAL y, REAL width, REAL height,
                        REAL startAngle, REAL sweepAngle);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathBezier(GpPath *path, REAL x1, REAL y1, REAL x2, REAL y2,
                           REAL x3, REAL y3, REAL x4, REAL y4);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathBeziers(GpPath *path, GDIPCONST GpPointF *points, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathCurve(GpPath *path, GDIPCONST GpPointF *points, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathCurve2(GpPath *path, GDIPCONST GpPointF *points, INT count,
                           REAL tension);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathCurve3(GpPath *path, GDIPCONST GpPointF *points, INT count,
                           INT offset, INT numberOfSegments, REAL tension);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathClosedCurve(GpPath *path, GDIPCONST GpPointF *points, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathClosedCurve2(GpPath *path, GDIPCONST GpPointF *points, INT count,
                                 REAL tension);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathRectangle(GpPath *path, REAL x, REAL y, REAL width, REAL height);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathRectangles(GpPath *path, GDIPCONST GpRectF *rects, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathEllipse(GpPath *path, REAL x, REAL y, REAL width,
                            REAL height);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathPie(GpPath *path, REAL x, REAL y, REAL width, REAL height,
                        REAL startAngle, REAL sweepAngle);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathPolygon(GpPath *path, GDIPCONST GpPointF *points, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathPath(GpPath *path, GDIPCONST GpPath* addingPath, BOOL connect);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathString(GpPath *path, GDIPCONST WCHAR *string,
                        INT length, GDIPCONST GpFontFamily *family, INT style,
                        REAL emSize, GDIPCONST GpRectF *layoutRect,
                        GDIPCONST GpStringFormat *format);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathStringI(GpPath *path, GDIPCONST WCHAR *string,
                        INT length, GDIPCONST GpFontFamily *family, INT style,
                        REAL emSize, GDIPCONST GpRect *layoutRect,
                        GDIPCONST GpStringFormat *format);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathLineI(GpPath *path, INT x1, INT y1, INT x2, INT y2);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathLine2I(GpPath *path, GDIPCONST GpPoint *points, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathArcI(GpPath *path, INT x, INT y, INT width, INT height,
                        REAL startAngle, REAL sweepAngle);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathBezierI(GpPath *path, INT x1, INT y1, INT x2, INT y2,
                           INT x3, INT y3, INT x4, INT y4);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathBeziersI(GpPath *path, GDIPCONST GpPoint *points, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathCurveI(GpPath *path, GDIPCONST GpPoint *points, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathCurve2I(GpPath *path, GDIPCONST GpPoint *points, INT count,
                           REAL tension);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathCurve3I(GpPath *path, GDIPCONST GpPoint *points, INT count,
                           INT offset, INT numberOfSegments, REAL tension);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathClosedCurveI(GpPath *path, GDIPCONST GpPoint *points, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathClosedCurve2I(GpPath *path, GDIPCONST GpPoint *points, INT count,
                                 REAL tension);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathRectangleI(GpPath *path, INT x, INT y, INT width, INT height);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathRectanglesI(GpPath *path, GDIPCONST GpRect *rects, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathEllipseI(GpPath *path, INT x, INT y, INT width, INT height);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathPieI(GpPath *path, INT x, INT y, INT width, INT height,
                        REAL startAngle, REAL sweepAngle);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipAddPathPolygonI(GpPath *path, GDIPCONST GpPoint *points, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFlattenPath(GpPath *path, GpMatrix* matrix, REAL flatness);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipWindingModeOutline(
    GpPath *path,
    GpMatrix *matrix,
    REAL flatness
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipWidenPath(
    GpPath *nativePath,
    GpPen *pen,
    GpMatrix *matrix,
    REAL flatness
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipWarpPath(GpPath *path, GpMatrix* matrix,
            GDIPCONST GpPointF *points, INT count,
            REAL srcx, REAL srcy, REAL srcwidth, REAL srcheight,
            GpWarpMode warpMode, REAL flatness);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipTransformPath(GpPath* path, GpMatrix* matrix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathWorldBounds(GpPath* path, GpRectF* bounds, 
                       GDIPCONST GpMatrix *matrix, GDIPCONST GpPen *pen);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathWorldBoundsI(GpPath* path, GpRect* bounds, 
                        GDIPCONST GpMatrix *matrix, GDIPCONST GpPen *pen);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipIsVisiblePathPoint(GpPath* path, REAL x, REAL y,
                       GpGraphics *graphics, BOOL *result);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipIsVisiblePathPointI(GpPath* path, INT x, INT y,
                        GpGraphics *graphics, BOOL *result);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipIsOutlineVisiblePathPoint(GpPath* path, REAL x, REAL y, GpPen *pen,
                              GpGraphics *graphics, BOOL *result);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipIsOutlineVisiblePathPointI(GpPath* path, INT x, INT y, GpPen *pen,
                               GpGraphics *graphics, BOOL *result);


//----------------------------------------------------------------------------
// PathIterator APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreatePathIter(GpPathIterator **iterator, GpPath* path);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDeletePathIter(GpPathIterator *iterator);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipPathIterNextSubpath(GpPathIterator* iterator, INT *resultCount,
        INT* startIndex, INT* endIndex, BOOL* isClosed);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipPathIterNextSubpathPath(GpPathIterator* iterator, INT* resultCount,
        GpPath* path, BOOL* isClosed);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipPathIterNextPathType(GpPathIterator* iterator, INT* resultCount,
        BYTE* pathType, INT* startIndex, INT* endIndex);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipPathIterNextMarker(GpPathIterator* iterator, INT *resultCount,
        INT* startIndex, INT* endIndex);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipPathIterNextMarkerPath(GpPathIterator* iterator, INT* resultCount,
        GpPath* path);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipPathIterGetCount(GpPathIterator* iterator, INT* count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipPathIterGetSubpathCount(GpPathIterator* iterator, INT* count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipPathIterIsValid(GpPathIterator* iterator, BOOL* valid);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipPathIterHasCurve(GpPathIterator* iterator, BOOL* hasCurve);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipPathIterRewind(GpPathIterator* iterator);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipPathIterEnumerate(GpPathIterator* iterator, INT* resultCount,
    GpPointF *points, BYTE *types, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipPathIterCopyData(GpPathIterator* iterator, INT* resultCount,
    GpPointF* points, BYTE* types, INT startIndex, INT endIndex);

//----------------------------------------------------------------------------
// Matrix APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateMatrix(GpMatrix **matrix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateMatrix2(REAL m11, REAL m12, REAL m21, REAL m22, REAL dx,
                                      REAL dy, GpMatrix **matrix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateMatrix3(GDIPCONST GpRectF *rect, GDIPCONST GpPointF *dstplg,
                                      GpMatrix **matrix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateMatrix3I(GDIPCONST GpRect *rect, GDIPCONST GpPoint *dstplg,
                                       GpMatrix **matrix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCloneMatrix(GpMatrix *matrix, GpMatrix **cloneMatrix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDeleteMatrix(GpMatrix *matrix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetMatrixElements(GpMatrix *matrix, REAL m11, REAL m12, REAL m21, REAL m22,
                      REAL dx, REAL dy);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipMultiplyMatrix(GpMatrix *matrix, GpMatrix* matrix2,
                            GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipTranslateMatrix(GpMatrix *matrix, REAL offsetX, REAL offsetY,
                    GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipScaleMatrix(GpMatrix *matrix, REAL scaleX, REAL scaleY,
                GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipRotateMatrix(GpMatrix *matrix, REAL angle, GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipShearMatrix(GpMatrix *matrix, REAL shearX, REAL shearY,
                GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipInvertMatrix(GpMatrix *matrix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipTransformMatrixPoints(GpMatrix *matrix, GpPointF *pts, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipTransformMatrixPointsI(GpMatrix *matrix, GpPoint *pts, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipVectorTransformMatrixPoints(GpMatrix *matrix, GpPointF *pts,
                                         INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipVectorTransformMatrixPointsI(GpMatrix *matrix, GpPoint *pts,
                                         INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetMatrixElements(GDIPCONST GpMatrix *matrix, REAL *matrixOut);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipIsMatrixInvertible(GDIPCONST GpMatrix *matrix, BOOL *result);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipIsMatrixIdentity(GDIPCONST GpMatrix *matrix, BOOL *result);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipIsMatrixEqual(GDIPCONST GpMatrix *matrix, GDIPCONST GpMatrix *matrix2, 
                  BOOL *result);

//----------------------------------------------------------------------------
// Region APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateRegion(GpRegion **region);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateRegionRect(GDIPCONST GpRectF *rect, GpRegion **region);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateRegionRectI(GDIPCONST GpRect *rect, GpRegion **region);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateRegionPath(GpPath *path, GpRegion **region);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateRegionRgnData(GDIPCONST BYTE *regionData, INT size, 
                        GpRegion **region);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateRegionHrgn(HRGN hRgn, GpRegion **region);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCloneRegion(GpRegion *region, GpRegion **cloneRegion);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDeleteRegion(GpRegion *region);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetInfinite(GpRegion *region);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetEmpty(GpRegion *region);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCombineRegionRect(GpRegion *region, GDIPCONST GpRectF *rect,
                      GpCombineMode combineMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCombineRegionRectI(GpRegion *region, GDIPCONST GpRect *rect,
                       GpCombineMode combineMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCombineRegionPath(GpRegion *region, GpPath *path, GpCombineMode combineMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCombineRegionRegion(GpRegion *region,  GpRegion *region2,
                        GpCombineMode combineMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipTranslateRegion(GpRegion *region, REAL dx, REAL dy);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipTranslateRegionI(GpRegion *region, INT dx, INT dy);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipTransformRegion(GpRegion *region, GpMatrix *matrix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetRegionBounds(GpRegion *region, GpGraphics *graphics,
                             GpRectF *rect);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetRegionBoundsI(GpRegion *region, GpGraphics *graphics,
                             GpRect *rect);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetRegionHRgn(GpRegion *region, GpGraphics *graphics, HRGN *hRgn);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipIsEmptyRegion(GpRegion *region, GpGraphics *graphics,
                           BOOL *result);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipIsInfiniteRegion(GpRegion *region, GpGraphics *graphics,
                              BOOL *result);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipIsEqualRegion(GpRegion *region, GpRegion *region2,
                           GpGraphics *graphics, BOOL *result);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetRegionDataSize(GpRegion *region, UINT * bufferSize);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetRegionData(GpRegion *region, BYTE * buffer, UINT bufferSize, 
                  UINT * sizeFilled);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipIsVisibleRegionPoint(GpRegion *region, REAL x, REAL y,
                                  GpGraphics *graphics, BOOL *result);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipIsVisibleRegionPointI(GpRegion *region, INT x, INT y,
                                  GpGraphics *graphics, BOOL *result);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipIsVisibleRegionRect(GpRegion *region, REAL x, REAL y, REAL width,
                        REAL height, GpGraphics *graphics, BOOL *result);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipIsVisibleRegionRectI(GpRegion *region, INT x, INT y, INT width,
                         INT height, GpGraphics *graphics, BOOL *result);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetRegionScansCount(GpRegion *region, UINT* count, GpMatrix* matrix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetRegionScans(GpRegion *region, GpRectF* rects, INT* count, 
                   GpMatrix* matrix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetRegionScansI(GpRegion *region, GpRect* rects, INT* count, 
                    GpMatrix* matrix);

//----------------------------------------------------------------------------
// Brush APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCloneBrush(GpBrush *brush, GpBrush **cloneBrush);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDeleteBrush(GpBrush *brush);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetBrushType(GpBrush *brush, GpBrushType *type);

//----------------------------------------------------------------------------
// HatchBrush APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateHatchBrush(GpHatchStyle hatchstyle, ARGB forecol,
                              ARGB backcol, GpHatch **brush);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetHatchStyle(GpHatch *brush, GpHatchStyle *hatchstyle);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetHatchForegroundColor(GpHatch *brush, ARGB* forecol);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetHatchBackgroundColor(GpHatch *brush, ARGB* backcol);

//----------------------------------------------------------------------------
// TextureBrush APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateTexture(GpImage *image, GpWrapMode wrapmode,
                           GpTexture **texture);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateTexture2(GpImage *image, GpWrapMode wrapmode, REAL x,
                   REAL y, REAL width, REAL height, GpTexture **texture);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateTextureIA(GpImage *image, 
                    GDIPCONST GpImageAttributes *imageAttributes,
                    REAL x, REAL y, REAL width, REAL height,
                    GpTexture **texture);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateTexture2I(GpImage *image, GpWrapMode wrapmode, INT x,
                    INT y, INT width, INT height, GpTexture **texture);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateTextureIAI(GpImage *image, 
                     GDIPCONST GpImageAttributes *imageAttributes,
                     INT x, INT y, INT width, INT height,
                     GpTexture **texture);


DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetTextureTransform(GpTexture *brush, GpMatrix *matrix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetTextureTransform(GpTexture *brush, GDIPCONST GpMatrix *matrix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipResetTextureTransform(GpTexture* brush);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipMultiplyTextureTransform(GpTexture* brush, GDIPCONST GpMatrix *matrix,
                            GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipTranslateTextureTransform(GpTexture* brush, REAL dx, REAL dy,
                            GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipScaleTextureTransform(GpTexture* brush, REAL sx, REAL sy,
                            GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipRotateTextureTransform(GpTexture* brush, REAL angle, GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetTextureWrapMode(GpTexture *brush, GpWrapMode wrapmode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetTextureWrapMode(GpTexture *brush, GpWrapMode *wrapmode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetTextureImage(GpTexture *brush, GpImage **image);

//----------------------------------------------------------------------------
// SolidBrush APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateSolidFill(ARGB color, GpSolidFill **brush);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetSolidFillColor(GpSolidFill *brush, ARGB color);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetSolidFillColor(GpSolidFill *brush, ARGB *color);

//----------------------------------------------------------------------------
// LineBrush APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateLineBrush(GDIPCONST GpPointF* point1,
                    GDIPCONST GpPointF* point2,
                    ARGB color1, ARGB color2,
                    GpWrapMode wrapMode,
                    GpLineGradient **lineGradient);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateLineBrushI(GDIPCONST GpPoint* point1,
                     GDIPCONST GpPoint* point2,
                     ARGB color1, ARGB color2,
                     GpWrapMode wrapMode,
                     GpLineGradient **lineGradient);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateLineBrushFromRect(GDIPCONST GpRectF* rect,
                            ARGB color1, ARGB color2,
                            GpLinearGradientMode mode,
                            GpWrapMode wrapMode,
                            GpLineGradient **lineGradient);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateLineBrushFromRectI(GDIPCONST GpRect* rect,
                             ARGB color1, ARGB color2,
                             GpLinearGradientMode mode,
                             GpWrapMode wrapMode,
                             GpLineGradient **lineGradient);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateLineBrushFromRectWithAngle(GDIPCONST GpRectF* rect,
                                     ARGB color1, ARGB color2,
                                     REAL angle,
                                     BOOL isAngleScalable,
                                     GpWrapMode wrapMode,
                                     GpLineGradient **lineGradient);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateLineBrushFromRectWithAngleI(GDIPCONST GpRect* rect,
                                     ARGB color1, ARGB color2,
                                     REAL angle,
                                     BOOL isAngleScalable,
                                     GpWrapMode wrapMode,
                                     GpLineGradient **lineGradient);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetLineColors(GpLineGradient *brush, ARGB color1, ARGB color2);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetLineColors(GpLineGradient *brush, ARGB* colors);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetLineRect(GpLineGradient *brush, GpRectF *rect);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetLineRectI(GpLineGradient *brush, GpRect *rect);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetLineGammaCorrection(GpLineGradient *brush, BOOL useGammaCorrection);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetLineGammaCorrection(GpLineGradient *brush, BOOL *useGammaCorrection);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetLineBlendCount(GpLineGradient *brush, INT *count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetLineBlend(GpLineGradient *brush, REAL *blend, REAL* positions,
                 INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetLineBlend(GpLineGradient *brush, GDIPCONST REAL *blend,
                 GDIPCONST REAL* positions, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetLinePresetBlendCount(GpLineGradient *brush, INT *count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetLinePresetBlend(GpLineGradient *brush, ARGB *blend,
                                           REAL* positions, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetLinePresetBlend(GpLineGradient *brush, GDIPCONST ARGB *blend,
                       GDIPCONST REAL* positions, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetLineSigmaBlend(GpLineGradient *brush, REAL focus, REAL scale);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetLineLinearBlend(GpLineGradient *brush, REAL focus, REAL scale);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetLineWrapMode(GpLineGradient *brush, GpWrapMode wrapmode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetLineWrapMode(GpLineGradient *brush, GpWrapMode *wrapmode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetLineTransform(GpLineGradient *brush, GpMatrix *matrix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetLineTransform(GpLineGradient *brush, GDIPCONST GpMatrix *matrix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipResetLineTransform(GpLineGradient* brush);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipMultiplyLineTransform(GpLineGradient* brush, GDIPCONST GpMatrix *matrix,
                            GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipTranslateLineTransform(GpLineGradient* brush, REAL dx, REAL dy,
                            GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipScaleLineTransform(GpLineGradient* brush, REAL sx, REAL sy,
                            GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipRotateLineTransform(GpLineGradient* brush, REAL angle, 
                        GpMatrixOrder order);

//----------------------------------------------------------------------------
// PathGradientBrush APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreatePathGradient(GDIPCONST GpPointF* points,
                                    INT count,
                                    GpWrapMode wrapMode,
                                    GpPathGradient **polyGradient);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreatePathGradientI(GDIPCONST GpPoint* points,
                                    INT count,
                                    GpWrapMode wrapMode,
                                    GpPathGradient **polyGradient);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreatePathGradientFromPath(GDIPCONST GpPath* path,
                                    GpPathGradient **polyGradient);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathGradientCenterColor(
                        GpPathGradient *brush, ARGB* colors);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPathGradientCenterColor(
                        GpPathGradient *brush, ARGB colors);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathGradientSurroundColorsWithCount(
                        GpPathGradient *brush, ARGB* color, INT* count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPathGradientSurroundColorsWithCount(
                        GpPathGradient *brush,
                        GDIPCONST ARGB* color, INT* count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathGradientPath(GpPathGradient *brush, GpPath *path);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPathGradientPath(GpPathGradient *brush, GDIPCONST GpPath *path);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathGradientCenterPoint(
                        GpPathGradient *brush, GpPointF* points);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathGradientCenterPointI(
                        GpPathGradient *brush, GpPoint* points);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPathGradientCenterPoint(
                        GpPathGradient *brush, GDIPCONST GpPointF* points);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPathGradientCenterPointI(
                        GpPathGradient *brush, GDIPCONST GpPoint* points);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathGradientRect(GpPathGradient *brush, GpRectF *rect);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathGradientRectI(GpPathGradient *brush, GpRect *rect);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathGradientPointCount(GpPathGradient *brush, INT* count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathGradientSurroundColorCount(GpPathGradient *brush, INT* count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPathGradientGammaCorrection(GpPathGradient *brush, 
                                   BOOL useGammaCorrection);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathGradientGammaCorrection(GpPathGradient *brush, 
                                   BOOL *useGammaCorrection);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathGradientBlendCount(GpPathGradient *brush,
                                             INT *count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathGradientBlend(GpPathGradient *brush,
                                    REAL *blend, REAL *positions, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPathGradientBlend(GpPathGradient *brush,
                GDIPCONST REAL *blend, GDIPCONST REAL *positions, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathGradientPresetBlendCount(GpPathGradient *brush, INT *count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathGradientPresetBlend(GpPathGradient *brush, ARGB *blend,
                                                REAL* positions, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPathGradientPresetBlend(GpPathGradient *brush, GDIPCONST ARGB *blend,
                                        GDIPCONST REAL* positions, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPathGradientSigmaBlend(GpPathGradient *brush, REAL focus, REAL scale);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPathGradientLinearBlend(GpPathGradient *brush, REAL focus, REAL scale);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathGradientWrapMode(GpPathGradient *brush,
                                         GpWrapMode *wrapmode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPathGradientWrapMode(GpPathGradient *brush,
                                         GpWrapMode wrapmode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathGradientTransform(GpPathGradient *brush,
                                          GpMatrix *matrix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPathGradientTransform(GpPathGradient *brush,
                                          GpMatrix *matrix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipResetPathGradientTransform(GpPathGradient* brush);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipMultiplyPathGradientTransform(GpPathGradient* brush, 
                                  GDIPCONST GpMatrix *matrix,
                                  GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipTranslatePathGradientTransform(GpPathGradient* brush, REAL dx, REAL dy,
                                   GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipScalePathGradientTransform(GpPathGradient* brush, REAL sx, REAL sy,
                               GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipRotatePathGradientTransform(GpPathGradient* brush, REAL angle,
                                GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPathGradientFocusScales(GpPathGradient *brush, REAL* xScale, 
                               REAL* yScale);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPathGradientFocusScales(GpPathGradient *brush, REAL xScale, 
                               REAL yScale);

//----------------------------------------------------------------------------
// Pen APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreatePen1(ARGB color, REAL width, GpUnit unit, GpPen **pen);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreatePen2(GpBrush *brush, REAL width, GpUnit unit,
                        GpPen **pen);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipClonePen(GpPen *pen, GpPen **clonepen);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDeletePen(GpPen *pen);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPenWidth(GpPen *pen, REAL width);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPenWidth(GpPen *pen, REAL *width);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPenUnit(GpPen *pen, GpUnit unit);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPenUnit(GpPen *pen, GpUnit *unit);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPenLineCap197819(GpPen *pen, GpLineCap startCap, GpLineCap endCap,
                  GpDashCap dashCap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPenStartCap(GpPen *pen, GpLineCap startCap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPenEndCap(GpPen *pen, GpLineCap endCap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPenDashCap197819(GpPen *pen, GpDashCap dashCap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPenStartCap(GpPen *pen, GpLineCap *startCap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPenEndCap(GpPen *pen, GpLineCap *endCap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPenDashCap197819(GpPen *pen, GpDashCap *dashCap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPenLineJoin(GpPen *pen, GpLineJoin lineJoin);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPenLineJoin(GpPen *pen, GpLineJoin *lineJoin);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPenCustomStartCap(GpPen *pen, GpCustomLineCap* customCap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPenCustomStartCap(GpPen *pen, GpCustomLineCap** customCap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPenCustomEndCap(GpPen *pen, GpCustomLineCap* customCap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPenCustomEndCap(GpPen *pen, GpCustomLineCap** customCap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPenMiterLimit(GpPen *pen, REAL miterLimit);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPenMiterLimit(GpPen *pen, REAL *miterLimit);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPenMode(GpPen *pen, GpPenAlignment penMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPenMode(GpPen *pen, GpPenAlignment *penMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPenTransform(GpPen *pen, GpMatrix *matrix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPenTransform(GpPen *pen, GpMatrix *matrix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipResetPenTransform(GpPen *pen);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipMultiplyPenTransform(GpPen *pen, GDIPCONST GpMatrix *matrix,
                           GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipTranslatePenTransform(GpPen *pen, REAL dx, REAL dy,
                            GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipScalePenTransform(GpPen *pen, REAL sx, REAL sy,
                            GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipRotatePenTransform(GpPen *pen, REAL angle, GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPenColor(GpPen *pen, ARGB argb);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPenColor(GpPen *pen, ARGB *argb);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPenBrushFill(GpPen *pen, GpBrush *brush);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPenBrushFill(GpPen *pen, GpBrush **brush);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPenFillType(GpPen *pen, GpPenType* type);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPenDashStyle(GpPen *pen, GpDashStyle *dashstyle);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPenDashStyle(GpPen *pen, GpDashStyle dashstyle);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPenDashOffset(GpPen *pen, REAL *offset);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPenDashOffset(GpPen *pen, REAL offset);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPenDashCount(GpPen *pen, INT *count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPenDashArray(GpPen *pen, GDIPCONST REAL *dash, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPenDashArray(GpPen *pen, REAL *dash, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPenCompoundCount(GpPen *pen, INT *count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPenCompoundArray(GpPen *pen, GDIPCONST REAL *dash, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPenCompoundArray(GpPen *pen, REAL *dash, INT count);

//----------------------------------------------------------------------------
// CustomLineCap APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateCustomLineCap(GpPath* fillPath, GpPath* strokePath,
   GpLineCap baseCap, REAL baseInset, GpCustomLineCap **customCap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDeleteCustomLineCap(GpCustomLineCap* customCap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCloneCustomLineCap(GpCustomLineCap* customCap,
                       GpCustomLineCap** clonedCap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetCustomLineCapType(GpCustomLineCap* customCap,
                       GpCustomLineCapType* capType);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetCustomLineCapStrokeCaps(GpCustomLineCap* customCap,
                               GpLineCap startCap, GpLineCap endCap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetCustomLineCapStrokeCaps(GpCustomLineCap* customCap,
                               GpLineCap* startCap, GpLineCap* endCap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetCustomLineCapStrokeJoin(GpCustomLineCap* customCap, 
                               GpLineJoin lineJoin);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetCustomLineCapStrokeJoin(GpCustomLineCap* customCap, 
                               GpLineJoin* lineJoin);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetCustomLineCapBaseCap(GpCustomLineCap* customCap, GpLineCap baseCap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetCustomLineCapBaseCap(GpCustomLineCap* customCap, GpLineCap* baseCap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetCustomLineCapBaseInset(GpCustomLineCap* customCap, REAL inset);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetCustomLineCapBaseInset(GpCustomLineCap* customCap, REAL* inset);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetCustomLineCapWidthScale(GpCustomLineCap* customCap, REAL widthScale);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetCustomLineCapWidthScale(GpCustomLineCap* customCap, REAL* widthScale);

//----------------------------------------------------------------------------
// AdjustableArrowCap APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateAdjustableArrowCap(REAL height, REAL width, BOOL isFilled,
                             GpAdjustableArrowCap **cap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetAdjustableArrowCapHeight(GpAdjustableArrowCap* cap, REAL height);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetAdjustableArrowCapHeight(GpAdjustableArrowCap* cap, REAL* height);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetAdjustableArrowCapWidth(GpAdjustableArrowCap* cap, REAL width);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetAdjustableArrowCapWidth(GpAdjustableArrowCap* cap, REAL* width);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetAdjustableArrowCapMiddleInset(GpAdjustableArrowCap* cap, 
                                     REAL middleInset);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetAdjustableArrowCapMiddleInset(GpAdjustableArrowCap* cap, 
                                     REAL* middleInset);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetAdjustableArrowCapFillState(GpAdjustableArrowCap* cap, BOOL fillState);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetAdjustableArrowCapFillState(GpAdjustableArrowCap* cap, BOOL* fillState);

//----------------------------------------------------------------------------
// Image APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipLoadImageFromStream(IStream* stream, GpImage **image);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipLoadImageFromFile(GDIPCONST WCHAR* filename, GpImage **image);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipLoadImageFromStreamICM(IStream* stream, GpImage **image);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipLoadImageFromFileICM(GDIPCONST WCHAR* filename, GpImage **image);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCloneImage(GpImage *image, GpImage **cloneImage);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDisposeImage(GpImage *image);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSaveImageToFile(GpImage *image, GDIPCONST WCHAR* filename,
                    GDIPCONST CLSID* clsidEncoder, 
                    GDIPCONST GpEncoderParameters* encoderParams);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSaveImageToStream(GpImage *image, IStream* stream,
                      GDIPCONST CLSID* clsidEncoder, 
                      GDIPCONST GpEncoderParameters* encoderParams);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSaveAdd(GpImage *image, GDIPCONST GpEncoderParameters* encoderParams);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSaveAddImage(GpImage *image, GpImage* newImage,
                 GDIPCONST GpEncoderParameters* encoderParams);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetImageGraphicsContext(GpImage *image, GpGraphics **graphics);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetImageBounds(GpImage *image, GpRectF *srcRect, GpUnit *srcUnit);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetImageDimension(GpImage *image, REAL *width, REAL *height);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetImageType(GpImage *image, GpImageType *type);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetImageWidth(GpImage *image, UINT *width);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetImageHeight(GpImage *image, UINT *height);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetImageHorizontalResolution(GpImage *image, REAL *resolution);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetImageVerticalResolution(GpImage *image, REAL *resolution);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetImageFlags(GpImage *image, UINT *flags);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetImageRawFormat(GpImage *image, GUID *format);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetImagePixelFormat(GpImage *image, GpPixelFormat *format);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetImageThumbnail(GpImage *image, UINT thumbWidth, UINT thumbHeight,
                      GpImage **thumbImage,
                      GpGetThumbnailImageAbort callback, VOID * callbackData);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetEncoderParameterListSize(GpImage *image, GDIPCONST CLSID* clsidEncoder,
                                UINT* size);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetEncoderParameterList(GpImage *image, GDIPCONST CLSID* clsidEncoder,
                            UINT size, GpEncoderParameters* buffer);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipImageGetFrameDimensionsCount(GpImage* image, UINT* count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipImageGetFrameDimensionsList(GpImage* image, GUID* dimensionIDs, 
                                UINT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipImageGetFrameCount(GpImage *image, GDIPCONST GUID* dimensionID, 
                       UINT* count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipImageSelectActiveFrame(GpImage *image, GDIPCONST GUID* dimensionID,
                           UINT frameIndex);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipImageRotateFlip(GpImage *image, GpRotateFlipType rfType);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetImagePalette(GpImage *image, GpColorPalette *palette, INT size);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetImagePalette(GpImage *image, GDIPCONST GpColorPalette *palette);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetImagePaletteSize(GpImage *image, INT *size);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPropertyCount(GpImage *image, UINT* numOfProperty);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPropertyIdList(GpImage *image, UINT numOfProperty, PROPID* list);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPropertyItemSize(GpImage *image, PROPID propId, UINT* size);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPropertyItem(GpImage *image, PROPID propId,UINT propSize,
                    GpPropertyItem* buffer);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPropertySize(GpImage *image, UINT* totalBufferSize, 
                    UINT* numProperties);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetAllPropertyItems(GpImage *image, UINT totalBufferSize,
                        UINT numProperties, GpPropertyItem* allItems);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipRemovePropertyItem(GpImage *image, PROPID propId);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPropertyItem(GpImage *image, GDIPCONST GpPropertyItem* item);

#if (GDIPVER >= 0x0110)
DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFindFirstImageItem(GpImage *image, GpImageItemData* item);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFindNextImageItem(GpImage *image, GpImageItemData* item);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetImageItemData(GpImage *image, GpImageItemData* item);
#endif //(GDIPVER >= 0x0110)

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipImageForceValidation(GpImage *image);

//----------------------------------------------------------------------------
// Bitmap APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateBitmapFromStream(IStream* stream, GpBitmap **bitmap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateBitmapFromFile(GDIPCONST WCHAR* filename, GpBitmap **bitmap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateBitmapFromStreamICM(IStream* stream, GpBitmap **bitmap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateBitmapFromFileICM(GDIPCONST WCHAR* filename, GpBitmap **bitmap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateBitmapFromScan0(INT width,
                          INT height,
                          INT stride,
                          GpPixelFormat format,
                          BYTE* scan0,
                          GpBitmap** bitmap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateBitmapFromGraphics(INT width,
                             INT height,
                             GpGraphics* target,
                             GpBitmap** bitmap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateBitmapFromDirectDrawSurface(struct IDirectDrawSurface7* surface,
                                      GpBitmap** bitmap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateBitmapFromGdiDib(GDIPCONST BITMAPINFO* gdiBitmapInfo,
                           VOID* gdiBitmapData,
                           GpBitmap** bitmap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateBitmapFromHBITMAP(HBITMAP hbm,
                            HPALETTE hpal,
                            GpBitmap** bitmap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateHBITMAPFromBitmap(GpBitmap* bitmap,
                            HBITMAP* hbmReturn,
                            ARGB background);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateBitmapFromHICON(HICON hicon,
                          GpBitmap** bitmap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateHICONFromBitmap(GpBitmap* bitmap,
                          HICON* hbmReturn);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateBitmapFromResource(HINSTANCE hInstance,
                             GDIPCONST WCHAR* lpBitmapName,
                             GpBitmap** bitmap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCloneBitmapArea(REAL x, REAL y, REAL width, REAL height,
                            GpPixelFormat format,
                            GpBitmap *srcBitmap,
                            GpBitmap **dstBitmap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCloneBitmapAreaI(INT x,
                     INT y,
                     INT width,
                     INT height,
                     GpPixelFormat format,
                     GpBitmap *srcBitmap,
                     GpBitmap **dstBitmap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipBitmapLockBits(GpBitmap* bitmap,
                   GDIPCONST GpRect* rect,
                   UINT flags,
                   GpPixelFormat format,
                   GpBitmapData* lockedBitmapData);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipBitmapUnlockBits(GpBitmap* bitmap,
                     GpBitmapData* lockedBitmapData);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipBitmapGetPixel(GpBitmap* bitmap, INT x, INT y, ARGB *color);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipBitmapSetPixel(GpBitmap* bitmap, INT x, INT y, ARGB color);

#if (GDIPVER >= 0x0110)
DECLSPEC_IMPORT GpStatus WINGDIPAPI GdipImageSetAbort(
    GpImage *pImage, 
    GdiplusAbort *pIAbort
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI GdipGraphicsSetAbort(
    GpGraphics *pGraphics, 
    GdiplusAbort *pIAbort
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipBitmapConvertFormat(
    IN GpBitmap *pInputBitmap,
    GpPixelFormat format,
    GpDitherType dithertype,
    GpPaletteType palettetype,
    GpColorPalette *palette,
    REAL alphaThresholdPercent
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipInitializePalette(
    OUT GpColorPalette *palette,   // output palette. must be allocated.
    GpPaletteType palettetype,     // palette enumeration type.
    INT optimalColors,           // how many optimal colors
    BOOL useTransparentColor,    // add a transparent color to the palette.
    GpBitmap *bitmap             // optional bitmap for median cut.
    );
    
DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipBitmapApplyEffect(
    GpBitmap* bitmap,
    GpEffect *effect,
    RECT *roi,
    BOOL useAuxData,
    VOID **auxData,
    INT *auxDataSize
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipBitmapCreateApplyEffect(
    GpBitmap **inputBitmaps,
    INT numInputs,
    GpEffect *effect,
    RECT *roi,
    RECT *outputRect,
    GpBitmap **outputBitmap,
    BOOL useAuxData,
    VOID **auxData,
    INT *auxDataSize
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipBitmapGetHistogram(
    GpBitmap* bitmap, 
    IN GpHistogramFormat format,
    IN UINT NumberOfEntries,
    __out_bcount(sizeof(UINT)*256) UINT *channel0,
    __out_bcount(sizeof(UINT)*256) UINT *channel1,
    __out_bcount(sizeof(UINT)*256) UINT *channel2,
    __out_bcount(sizeof(UINT)*256) UINT *channel3
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipBitmapGetHistogramSize(
    IN GpHistogramFormat format,
    OUT UINT *NumberOfEntries
);
#endif

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipBitmapSetResolution(GpBitmap* bitmap, REAL xdpi, REAL ydpi);

//----------------------------------------------------------------------------
// ImageAttributes APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateImageAttributes(GpImageAttributes **imageattr);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCloneImageAttributes(GDIPCONST GpImageAttributes *imageattr,
                         GpImageAttributes **cloneImageattr);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDisposeImageAttributes(GpImageAttributes *imageattr);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetImageAttributesToIdentity(GpImageAttributes *imageattr,
                                 GpColorAdjustType type);
DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipResetImageAttributes(GpImageAttributes *imageattr,
                         GpColorAdjustType type);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetImageAttributesColorMatrix(GpImageAttributes *imageattr,
                               GpColorAdjustType type,
                               BOOL enableFlag,
                               GDIPCONST GpColorMatrix* colorMatrix,
                               GDIPCONST GpColorMatrix* grayMatrix,
                               GpColorMatrixFlags flags);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetImageAttributesThreshold(GpImageAttributes *imageattr,
                                GpColorAdjustType type,
                                BOOL enableFlag,
                                REAL threshold);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetImageAttributesGamma(GpImageAttributes *imageattr,
                            GpColorAdjustType type,
                            BOOL enableFlag,
                            REAL gamma);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetImageAttributesNoOp(GpImageAttributes *imageattr,
                           GpColorAdjustType type,
                           BOOL enableFlag);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetImageAttributesColorKeys(GpImageAttributes *imageattr,
                                GpColorAdjustType type,
                                BOOL enableFlag,
                                ARGB colorLow,
                                ARGB colorHigh);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetImageAttributesOutputChannel(GpImageAttributes *imageattr,
                                    GpColorAdjustType type,
                                    BOOL enableFlag,
                                    GpColorChannelFlags channelFlags);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetImageAttributesOutputChannelColorProfile(GpImageAttributes *imageattr,
                                                GpColorAdjustType type,
                                                BOOL enableFlag,
                                                GDIPCONST 
                                                  WCHAR *colorProfileFilename);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetImageAttributesRemapTable(GpImageAttributes *imageattr,
                                 GpColorAdjustType type,
                                 BOOL enableFlag,
                                 UINT mapSize,
                                 GDIPCONST GpColorMap *map);
DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetImageAttributesWrapMode(
    GpImageAttributes *imageAttr,
    GpWrapMode wrap,
    ARGB argb,
    BOOL clamp
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetImageAttributesICMMode(
    GpImageAttributes *imageAttr,
    BOOL on
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetImageAttributesAdjustedPalette(
    GpImageAttributes *imageAttr,
    GpColorPalette * colorPalette,
    GpColorAdjustType colorAdjustType
);

//----------------------------------------------------------------------------
// Graphics APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFlush(GpGraphics *graphics, GpFlushIntention intention);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateFromHDC(HDC hdc, GpGraphics **graphics);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateFromHDC2(HDC hdc, HANDLE hDevice, GpGraphics **graphics);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateFromHWND(HWND hwnd, GpGraphics **graphics);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateFromHWNDICM(HWND hwnd, GpGraphics **graphics);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDeleteGraphics(GpGraphics *graphics);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetDC(GpGraphics* graphics, HDC * hdc);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipReleaseDC(GpGraphics* graphics, HDC hdc);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetCompositingMode(GpGraphics *graphics, GpCompositingMode compositingMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetCompositingMode(GpGraphics *graphics, GpCompositingMode *compositingMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetRenderingOrigin(GpGraphics *graphics, INT x, INT y);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetRenderingOrigin(GpGraphics *graphics, INT *x, INT *y);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetCompositingQuality(GpGraphics *graphics, 
                          GpCompositingQuality compositingQuality);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetCompositingQuality(GpGraphics *graphics, 
                          GpCompositingQuality *compositingQuality);
                          
DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetSmoothingMode(GpGraphics *graphics, GpSmoothingMode smoothingMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetSmoothingMode(GpGraphics *graphics, GpSmoothingMode *smoothingMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPixelOffsetMode(GpGraphics* graphics, GpPixelOffsetMode pixelOffsetMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPixelOffsetMode(GpGraphics *graphics, GpPixelOffsetMode *pixelOffsetMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetTextRenderingHint(GpGraphics *graphics, GpTextRenderingHint mode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetTextRenderingHint(GpGraphics *graphics, GpTextRenderingHint *mode);

DECLSPEC_IMPORT GpStatus  WINGDIPAPI
GdipSetTextContrast(GpGraphics *graphics, UINT contrast);

DECLSPEC_IMPORT GpStatus  WINGDIPAPI
GdipGetTextContrast(GpGraphics *graphics, UINT * contrast);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetInterpolationMode(GpGraphics *graphics, 
                         GpInterpolationMode interpolationMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetInterpolationMode(GpGraphics *graphics, 
                         GpInterpolationMode *interpolationMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetWorldTransform(GpGraphics *graphics, GpMatrix *matrix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipResetWorldTransform(GpGraphics *graphics);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipMultiplyWorldTransform(GpGraphics *graphics, GDIPCONST GpMatrix *matrix,
                           GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipTranslateWorldTransform(GpGraphics *graphics, REAL dx, REAL dy,
                            GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipScaleWorldTransform(GpGraphics *graphics, REAL sx, REAL sy,
                        GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipRotateWorldTransform(GpGraphics *graphics, REAL angle, 
                         GpMatrixOrder order);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetWorldTransform(GpGraphics *graphics, GpMatrix *matrix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipResetPageTransform(GpGraphics *graphics);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPageUnit(GpGraphics *graphics, GpUnit *unit);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetPageScale(GpGraphics *graphics, REAL *scale);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPageUnit(GpGraphics *graphics, GpUnit unit);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetPageScale(GpGraphics *graphics, REAL scale);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetDpiX(GpGraphics *graphics, REAL* dpi);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetDpiY(GpGraphics *graphics, REAL* dpi);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipTransformPoints(GpGraphics *graphics, GpCoordinateSpace destSpace,
                             GpCoordinateSpace srcSpace, GpPointF *points,
                             INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipTransformPointsI(GpGraphics *graphics, GpCoordinateSpace destSpace,
                             GpCoordinateSpace srcSpace, GpPoint *points,
                             INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetNearestColor(GpGraphics *graphics, ARGB* argb);

// Creates the Win9x Halftone Palette (even on NT) with correct Desktop colors
DECLSPEC_IMPORT HPALETTE WINGDIPAPI
GdipCreateHalftonePalette();

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawLine(GpGraphics *graphics, GpPen *pen, REAL x1, REAL y1,
                      REAL x2, REAL y2);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawLineI(GpGraphics *graphics, GpPen *pen, INT x1, INT y1,
                      INT x2, INT y2);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawLines(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPointF *points,
                       INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawLinesI(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPoint *points,
                       INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawArc(GpGraphics *graphics, GpPen *pen, REAL x, REAL y,
            REAL width, REAL height, REAL startAngle, REAL sweepAngle);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawArcI(GpGraphics *graphics, GpPen *pen, INT x, INT y,
                     INT width, INT height, REAL startAngle, REAL sweepAngle);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawBezier(GpGraphics *graphics, GpPen *pen, REAL x1, REAL y1,
                        REAL x2, REAL y2, REAL x3, REAL y3, REAL x4, REAL y4);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawBezierI(GpGraphics *graphics, GpPen *pen, INT x1, INT y1,
                        INT x2, INT y2, INT x3, INT y3, INT x4, INT y4);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawBeziers(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPointF *points,
                         INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawBeziersI(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPoint *points,
                         INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawRectangle(GpGraphics *graphics, GpPen *pen, REAL x, REAL y,
                      REAL width, REAL height);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawRectangleI(GpGraphics *graphics, GpPen *pen, INT x, INT y,
                      INT width, INT height);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawRectangles(GpGraphics *graphics, GpPen *pen, GDIPCONST GpRectF *rects,
                       INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawRectanglesI(GpGraphics *graphics, GpPen *pen, GDIPCONST GpRect *rects,
                       INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawEllipse(GpGraphics *graphics, GpPen *pen, REAL x, REAL y,
                         REAL width, REAL height);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawEllipseI(GpGraphics *graphics, GpPen *pen, INT x, INT y,
                         INT width, INT height);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawPie(GpGraphics *graphics, GpPen *pen, REAL x, REAL y,
                     REAL width, REAL height, REAL startAngle, 
            REAL sweepAngle);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawPieI(GpGraphics *graphics, GpPen *pen, INT x, INT y,
                     INT width, INT height, REAL startAngle, REAL sweepAngle);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawPolygon(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPointF *points,
                         INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawPolygonI(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPoint *points,
                         INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawPath(GpGraphics *graphics, GpPen *pen, GpPath *path);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawCurve(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPointF *points,
                       INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawCurveI(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPoint *points,
                       INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawCurve2(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPointF *points,
                       INT count, REAL tension);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawCurve2I(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPoint *points,
                       INT count, REAL tension);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawCurve3(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPointF *points,
               INT count, INT offset, INT numberOfSegments, REAL tension);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawCurve3I(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPoint *points,
                INT count, INT offset, INT numberOfSegments, REAL tension);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawClosedCurve(GpGraphics *graphics, GpPen *pen,
                    GDIPCONST GpPointF *points, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawClosedCurveI(GpGraphics *graphics, GpPen *pen,
                     GDIPCONST GpPoint *points, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawClosedCurve2(GpGraphics *graphics, GpPen *pen,
                     GDIPCONST GpPointF *points, INT count, REAL tension);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawClosedCurve2I(GpGraphics *graphics, GpPen *pen,
                      GDIPCONST GpPoint *points, INT count, REAL tension);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGraphicsClear(GpGraphics *graphics, ARGB color);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFillRectangle(GpGraphics *graphics, GpBrush *brush, REAL x, REAL y,
                  REAL width, REAL height);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFillRectangleI(GpGraphics *graphics, GpBrush *brush, INT x, INT y,
                   INT width, INT height);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFillRectangles(GpGraphics *graphics, GpBrush *brush,
                   GDIPCONST GpRectF *rects, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFillRectanglesI(GpGraphics *graphics, GpBrush *brush,
                    GDIPCONST GpRect *rects, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFillPolygon(GpGraphics *graphics, GpBrush *brush,
                GDIPCONST GpPointF *points, INT count, GpFillMode fillMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFillPolygonI(GpGraphics *graphics, GpBrush *brush,
                 GDIPCONST GpPoint *points, INT count, GpFillMode fillMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFillPolygon2(GpGraphics *graphics, GpBrush *brush,
                 GDIPCONST GpPointF *points, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFillPolygon2I(GpGraphics *graphics, GpBrush *brush,
                  GDIPCONST GpPoint *points, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFillEllipse(GpGraphics *graphics, GpBrush *brush, REAL x, REAL y,
                REAL width, REAL height);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFillEllipseI(GpGraphics *graphics, GpBrush *brush, INT x, INT y,
                 INT width, INT height);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFillPie(GpGraphics *graphics, GpBrush *brush, REAL x, REAL y,
            REAL width, REAL height, REAL startAngle, REAL sweepAngle);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFillPieI(GpGraphics *graphics, GpBrush *brush, INT x, INT y,
             INT width, INT height, REAL startAngle, REAL sweepAngle);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFillPath(GpGraphics *graphics, GpBrush *brush, GpPath *path);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFillClosedCurve(GpGraphics *graphics, GpBrush *brush,
                              GDIPCONST GpPointF *points, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFillClosedCurveI(GpGraphics *graphics, GpBrush *brush,
                              GDIPCONST GpPoint *points, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFillClosedCurve2(GpGraphics *graphics, GpBrush *brush,
                              GDIPCONST GpPointF *points, INT count,
                              REAL tension, GpFillMode fillMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFillClosedCurve2I(GpGraphics *graphics, GpBrush *brush,
                              GDIPCONST GpPoint *points, INT count,
                              REAL tension, GpFillMode fillMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFillRegion(GpGraphics *graphics, GpBrush *brush,
                        GpRegion *region);

#if (GDIPVER >= 0x0110)
DECLSPEC_IMPORT GpStatus
WINGDIPAPI
GdipDrawImageFX(
    GpGraphics *graphics,
    GpImage *image,
    GpRectF *source,
    GpMatrix *xForm,
    GpEffect *effect,
    GpImageAttributes *imageAttributes,
    GpUnit srcUnit
    );
#endif //(GDIPVER >= 0x0110)

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawImage(GpGraphics *graphics, GpImage *image, REAL x, REAL y);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawImageI(GpGraphics *graphics, GpImage *image, INT x, INT y);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawImageRect(GpGraphics *graphics, GpImage *image, REAL x, REAL y,
                           REAL width, REAL height);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawImageRectI(GpGraphics *graphics, GpImage *image, INT x, INT y,
                           INT width, INT height);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawImagePoints(GpGraphics *graphics, GpImage *image,
                             GDIPCONST GpPointF *dstpoints, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawImagePointsI(GpGraphics *graphics, GpImage *image,
                             GDIPCONST GpPoint *dstpoints, INT count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawImagePointRect(GpGraphics *graphics, GpImage *image, REAL x,
                                REAL y, REAL srcx, REAL srcy, REAL srcwidth,
                                REAL srcheight, GpUnit srcUnit);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawImagePointRectI(GpGraphics *graphics, GpImage *image, INT x,
                                INT y, INT srcx, INT srcy, INT srcwidth,
                                INT srcheight, GpUnit srcUnit);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawImageRectRect(GpGraphics *graphics, GpImage *image, REAL dstx,
                      REAL dsty, REAL dstwidth, REAL dstheight,
                      REAL srcx, REAL srcy, REAL srcwidth, REAL srcheight,
                      GpUnit srcUnit,
                      GDIPCONST GpImageAttributes* imageAttributes,
                      GpDrawImageAbort callback, VOID * callbackData);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawImageRectRectI(GpGraphics *graphics, GpImage *image, INT dstx,
                       INT dsty, INT dstwidth, INT dstheight,
                       INT srcx, INT srcy, INT srcwidth, INT srcheight,
                       GpUnit srcUnit,
                       GDIPCONST GpImageAttributes* imageAttributes,
                       GpDrawImageAbort callback, VOID * callbackData);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawImagePointsRect(GpGraphics *graphics, GpImage *image,
                        GDIPCONST GpPointF *points, INT count, REAL srcx,
                        REAL srcy, REAL srcwidth, REAL srcheight,
                        GpUnit srcUnit,
                        GDIPCONST GpImageAttributes* imageAttributes,
                        GpDrawImageAbort callback, VOID * callbackData);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawImagePointsRectI(GpGraphics *graphics, GpImage *image,
                         GDIPCONST GpPoint *points, INT count, INT srcx,
                         INT srcy, INT srcwidth, INT srcheight,
                         GpUnit srcUnit,
                         GDIPCONST GpImageAttributes* imageAttributes,
                         GpDrawImageAbort callback, VOID * callbackData);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipEnumerateMetafileDestPoint(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST GpPointF *    destPoint,
    GpEnumerateMetafileProc callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipEnumerateMetafileDestPointI(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST GpPoint *     destPoint,
    GpEnumerateMetafileProc callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipEnumerateMetafileDestRect(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST GpRectF *     destRect,
    GpEnumerateMetafileProc callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipEnumerateMetafileDestRectI(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST GpRect *      destRect,
    GpEnumerateMetafileProc callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipEnumerateMetafileDestPoints(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST GpPointF *    destPoints,
    INT                     count,
    GpEnumerateMetafileProc callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipEnumerateMetafileDestPointsI(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST GpPoint *     destPoints,
    INT                     count,
    GpEnumerateMetafileProc callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipEnumerateMetafileSrcRectDestPoint(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST GpPointF *    destPoint,
    GDIPCONST GpRectF *     srcRect,
    GpUnit                  srcUnit,
    GpEnumerateMetafileProc callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipEnumerateMetafileSrcRectDestPointI(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST GpPoint *     destPoint,
    GDIPCONST GpRect *      srcRect,
    GpUnit                  srcUnit,
    GpEnumerateMetafileProc callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipEnumerateMetafileSrcRectDestRect(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST GpRectF *     destRect,
    GDIPCONST GpRectF *     srcRect,
    GpUnit                  srcUnit,
    GpEnumerateMetafileProc callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipEnumerateMetafileSrcRectDestRectI(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST GpRect *      destRect,
    GDIPCONST GpRect *      srcRect,
    GpUnit                  srcUnit,
    GpEnumerateMetafileProc callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipEnumerateMetafileSrcRectDestPoints(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST GpPointF *    destPoints,
    INT                     count,
    GDIPCONST GpRectF *     srcRect,
    GpUnit                  srcUnit,
    GpEnumerateMetafileProc callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipEnumerateMetafileSrcRectDestPointsI(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST GpPoint *     destPoints,
    INT                     count,
    GDIPCONST GpRect *      srcRect,
    GpUnit                  srcUnit,
    GpEnumerateMetafileProc callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipPlayMetafileRecord(
    GDIPCONST GpMetafile *  metafile,
    GpEmfPlusRecordType     recordType,
    UINT                    flags,
    UINT                    dataSize,
    GDIPCONST BYTE *        data
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetClipGraphics(GpGraphics *graphics, GpGraphics *srcgraphics,
                    GpCombineMode combineMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetClipRect(GpGraphics *graphics, REAL x, REAL y,
                         REAL width, REAL height, GpCombineMode combineMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetClipRectI(GpGraphics *graphics, INT x, INT y,
                         INT width, INT height, GpCombineMode combineMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetClipPath(GpGraphics *graphics, GpPath *path, GpCombineMode combineMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetClipRegion(GpGraphics *graphics, GpRegion *region,
                  GpCombineMode combineMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetClipHrgn(GpGraphics *graphics, HRGN hRgn, GpCombineMode combineMode);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipResetClip(GpGraphics *graphics);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipTranslateClip(GpGraphics *graphics, REAL dx, REAL dy);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipTranslateClipI(GpGraphics *graphics, INT dx, INT dy);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetClip(GpGraphics *graphics, GpRegion *region);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetClipBounds(GpGraphics *graphics, GpRectF *rect);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetClipBoundsI(GpGraphics *graphics, GpRect *rect);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipIsClipEmpty(GpGraphics *graphics, BOOL *result);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetVisibleClipBounds(GpGraphics *graphics, GpRectF *rect);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetVisibleClipBoundsI(GpGraphics *graphics, GpRect *rect);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipIsVisibleClipEmpty(GpGraphics *graphics, BOOL *result);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipIsVisiblePoint(GpGraphics *graphics, REAL x, REAL y,
                           BOOL *result);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipIsVisiblePointI(GpGraphics *graphics, INT x, INT y,
                           BOOL *result);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipIsVisibleRect(GpGraphics *graphics, REAL x, REAL y,
                           REAL width, REAL height, BOOL *result);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipIsVisibleRectI(GpGraphics *graphics, INT x, INT y,
                           INT width, INT height, BOOL *result);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSaveGraphics(GpGraphics *graphics, GpGraphicsState *state);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipRestoreGraphics(GpGraphics *graphics, GpGraphicsState state);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipBeginContainer(GpGraphics *graphics, GDIPCONST GpRectF* dstrect,
                   GDIPCONST GpRectF *srcrect, GpUnit unit, 
                   GpGraphicsContainer *state);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipBeginContainerI(GpGraphics *graphics, GDIPCONST GpRect* dstrect,
                    GDIPCONST GpRect *srcrect, GpUnit unit, 
                    GpGraphicsContainer *state);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipBeginContainer2(GpGraphics *graphics, GpGraphicsContainer* state);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipEndContainer(GpGraphics *graphics, GpGraphicsContainer state);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetMetafileHeaderFromWmf(
    HMETAFILE           hWmf,
    GDIPCONST GpWmfPlaceableFileHeader *   wmfPlaceableFileHeader,
    GpMetafileHeader *    header
    );

DECLSPEC_IMPORT GpStatus
WINGDIPAPI
GdipGetMetafileHeaderFromEmf(
    HENHMETAFILE        hEmf,
    GpMetafileHeader *  header
    );

DECLSPEC_IMPORT GpStatus
WINGDIPAPI
GdipGetMetafileHeaderFromFile(
    GDIPCONST WCHAR*        filename,
    GpMetafileHeader *      header
    );

DECLSPEC_IMPORT GpStatus
WINGDIPAPI
GdipGetMetafileHeaderFromStream(
    IStream *           stream,
    GpMetafileHeader *  header
    );

DECLSPEC_IMPORT GpStatus
WINGDIPAPI
GdipGetMetafileHeaderFromMetafile(
    GpMetafile *        metafile,
    GpMetafileHeader *  header
    );

DECLSPEC_IMPORT GpStatus
WINGDIPAPI
GdipGetHemfFromMetafile(
    GpMetafile *        metafile,
    HENHMETAFILE *      hEmf
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateStreamOnFile(GDIPCONST WCHAR * filename, UINT access, 
                       IStream **stream);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateMetafileFromWmf(HMETAFILE hWmf, BOOL deleteWmf,
                          GDIPCONST GpWmfPlaceableFileHeader * wmfPlaceableFileHeader, 
                          GpMetafile **metafile);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateMetafileFromEmf(HENHMETAFILE hEmf, BOOL deleteEmf,
                          GpMetafile **metafile);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateMetafileFromFile(GDIPCONST WCHAR* file, GpMetafile **metafile);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateMetafileFromWmfFile(GDIPCONST WCHAR* file, 
                              GDIPCONST GpWmfPlaceableFileHeader * wmfPlaceableFileHeader, 
                              GpMetafile **metafile);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateMetafileFromStream(IStream * stream, GpMetafile **metafile);


DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipRecordMetafile(
    HDC                 referenceHdc,
    GpEmfType           type,
    GDIPCONST GpRectF * frameRect,
    GpMetafileFrameUnit frameUnit,
    GDIPCONST WCHAR *   description,
    GpMetafile **       metafile
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipRecordMetafileI(
    HDC                 referenceHdc,
    GpEmfType           type,
    GDIPCONST GpRect *  frameRect,
    GpMetafileFrameUnit frameUnit,
    GDIPCONST WCHAR *   description,
    GpMetafile **       metafile
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipRecordMetafileFileName(
    GDIPCONST WCHAR*    fileName,
    HDC                 referenceHdc,
    GpEmfType           type,
    GDIPCONST GpRectF * frameRect,
    GpMetafileFrameUnit frameUnit,
    GDIPCONST WCHAR *   description,
    GpMetafile **       metafile
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipRecordMetafileFileNameI(
    GDIPCONST WCHAR*    fileName,
    HDC                 referenceHdc,
    GpEmfType           type,
    GDIPCONST GpRect *  frameRect,
    GpMetafileFrameUnit frameUnit,
    GDIPCONST WCHAR *   description,
    GpMetafile **       metafile
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipRecordMetafileStream(
    IStream *           stream,
    HDC                 referenceHdc,
    GpEmfType             type,
    GDIPCONST GpRectF * frameRect,
    GpMetafileFrameUnit   frameUnit,
    GDIPCONST WCHAR *   description,
    GpMetafile **       metafile
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipRecordMetafileStreamI(
    IStream *           stream,
    HDC                 referenceHdc,
    GpEmfType           type,
    GDIPCONST GpRect *  frameRect,
    GpMetafileFrameUnit frameUnit,
    GDIPCONST WCHAR *   description,
    GpMetafile **       metafile
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetMetafileDownLevelRasterizationLimit(
    GpMetafile *            metafile,
    UINT                    metafileRasterizationLimitDpi
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetMetafileDownLevelRasterizationLimit(
    GDIPCONST GpMetafile *  metafile,
    UINT *                  metafileRasterizationLimitDpi
    );

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetImageDecodersSize(UINT *numDecoders, UINT *size);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetImageDecoders(UINT numDecoders,
                     UINT size,
                     __out_bcount(size) GpImageCodecInfo *decoders);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetImageEncodersSize(UINT *numEncoders, UINT *size);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetImageEncoders(UINT numEncoders,
                     UINT size,
                     __out_bcount(size) GpImageCodecInfo *encoders);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipComment(GpGraphics* graphics, UINT sizeData, GDIPCONST BYTE * data);

//----------------------------------------------------------------------------
// FontFamily APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateFontFamilyFromName(GDIPCONST WCHAR *name,
                             GpFontCollection *fontCollection,
                             GpFontFamily **fontFamily);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDeleteFontFamily(GpFontFamily *fontFamily);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCloneFontFamily(GpFontFamily *fontFamily, GpFontFamily **clonedFontFamily);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetGenericFontFamilySansSerif(GpFontFamily **nativeFamily);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetGenericFontFamilySerif(GpFontFamily **nativeFamily);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetGenericFontFamilyMonospace(GpFontFamily **nativeFamily);


DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetFamilyName(
    GDIPCONST GpFontFamily              *family,
    __out_ecount(LF_FACESIZE) LPWSTR    name,
    LANGID                              language
);

DECLSPEC_IMPORT GpStatus   WINGDIPAPI
GdipIsStyleAvailable(GDIPCONST GpFontFamily *family, INT style, 
                     BOOL * IsStyleAvailable);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipFontCollectionEnumerable(
    GpFontCollection* fontCollection,
    GpGraphics* graphics,
    INT *       numFound
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI GdipFontCollectionEnumerate(
    GpFontCollection* fontCollection,
    INT             numSought,
    GpFontFamily*   gpfamilies[],
    INT*            numFound,
    GpGraphics*     graphics
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetEmHeight(GDIPCONST GpFontFamily *family, INT style, 
                UINT16 * EmHeight);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetCellAscent(GDIPCONST GpFontFamily *family, INT style,
                  UINT16 * CellAscent);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetCellDescent(GDIPCONST GpFontFamily *family, INT style, 
                   UINT16 * CellDescent);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetLineSpacing(GDIPCONST GpFontFamily *family, INT style, 
                   UINT16 * LineSpacing);


//----------------------------------------------------------------------------
// Font APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateFontFromDC(
    HDC        hdc,
    GpFont   **font
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateFontFromLogfontA(
    HDC        hdc,
    GDIPCONST LOGFONTA  *logfont,
    GpFont   **font
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateFontFromLogfontW(
    HDC        hdc,
    GDIPCONST LOGFONTW  *logfont,
    GpFont   **font
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateFont(
    GDIPCONST GpFontFamily  *fontFamily,
    REAL                 emSize,
    INT                  style,
    GpUnit               unit,
    GpFont             **font
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCloneFont(GpFont* font, GpFont** cloneFont);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDeleteFont(GpFont* font);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetFamily(GpFont *font, GpFontFamily **family);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetFontStyle(GpFont *font, INT *style);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetFontSize(GpFont *font, REAL *size);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetFontUnit(GpFont *font, GpUnit *unit);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetFontHeight(GDIPCONST GpFont *font, GDIPCONST GpGraphics *graphics, 
                  REAL *height);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetFontHeightGivenDPI(GDIPCONST GpFont *font, REAL dpi, REAL *height);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetLogFontA(GpFont * font, GpGraphics *graphics, LOGFONTA * logfontA);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetLogFontW(GpFont * font, GpGraphics *graphics, LOGFONTW * logfontW);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipNewInstalledFontCollection(GpFontCollection** fontCollection);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipNewPrivateFontCollection(GpFontCollection** fontCollection);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDeletePrivateFontCollection(GpFontCollection** fontCollection);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetFontCollectionFamilyCount(
    GpFontCollection* fontCollection,
    INT *       numFound
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetFontCollectionFamilyList(
    GpFontCollection* fontCollection,
    INT             numSought,
    GpFontFamily*   gpfamilies[],
    INT*            numFound
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipPrivateAddFontFile(
    GpFontCollection* fontCollection,
    GDIPCONST WCHAR* filename
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipPrivateAddMemoryFont(
    GpFontCollection* fontCollection,
    GDIPCONST void* memory,
    INT length
);

//----------------------------------------------------------------------------
// Text APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawString(
    GpGraphics               *graphics,
    GDIPCONST WCHAR          *string,
    INT                       length,
    GDIPCONST GpFont         *font,
    GDIPCONST GpRectF        *layoutRect,
    GDIPCONST GpStringFormat *stringFormat,
    GDIPCONST GpBrush        *brush
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipMeasureString(
    GpGraphics               *graphics,
    GDIPCONST WCHAR          *string,
    INT                       length,
    GDIPCONST GpFont         *font,
    GDIPCONST GpRectF        *layoutRect,
    GDIPCONST GpStringFormat *stringFormat,
    GpRectF                  *boundingBox,
    INT                      *codepointsFitted,
    INT                      *linesFilled
);

DECLSPEC_IMPORT GpStatus
WINGDIPAPI
GdipMeasureCharacterRanges(
    GpGraphics               *graphics,
    GDIPCONST WCHAR          *string,
    INT                       length,
    GDIPCONST GpFont         *font,
    GDIPCONST GpRectF        *layoutRect,
    GDIPCONST GpStringFormat *stringFormat,
    INT                       regionCount,
    GpRegion                **regions
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawDriverString(
    GpGraphics *graphics,
    GDIPCONST UINT16 *text,
    INT length,
    GDIPCONST GpFont *font,
    GDIPCONST GpBrush *brush,
    GDIPCONST GpPointF *positions,
    INT flags,
    GDIPCONST GpMatrix *matrix
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipMeasureDriverString(
    GpGraphics *graphics,
    GDIPCONST UINT16 *text,
    INT length,
    GDIPCONST GpFont *font,
    GDIPCONST GpPointF *positions,
    INT flags,
    GDIPCONST GpMatrix *matrix,
    GpRectF *boundingBox
);

//----------------------------------------------------------------------------
// String format APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateStringFormat(
    INT               formatAttributes,
    LANGID            language,
    GpStringFormat  **format
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipStringFormatGetGenericDefault(GpStringFormat **format);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipStringFormatGetGenericTypographic(GpStringFormat **format);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDeleteStringFormat(GpStringFormat *format);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCloneStringFormat(GDIPCONST GpStringFormat *format, 
                      GpStringFormat **newFormat);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetStringFormatFlags(GpStringFormat *format, INT flags);

DECLSPEC_IMPORT GpStatus WINGDIPAPI GdipGetStringFormatFlags(GDIPCONST GpStringFormat *format,
                                             INT *flags);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetStringFormatAlign(GpStringFormat *format, GpStringAlignment align);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetStringFormatAlign(GDIPCONST GpStringFormat *format, 
                         GpStringAlignment *align);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetStringFormatLineAlign(GpStringFormat *format,
                             GpStringAlignment align);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetStringFormatLineAlign(GDIPCONST GpStringFormat *format,
                             GpStringAlignment *align);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetStringFormatTrimming(
    GpStringFormat  *format,
    GpStringTrimming trimming
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetStringFormatTrimming(
    GDIPCONST GpStringFormat *format,
    GpStringTrimming         *trimming
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetStringFormatHotkeyPrefix(GpStringFormat *format, INT hotkeyPrefix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetStringFormatHotkeyPrefix(GDIPCONST GpStringFormat *format, 
                                INT *hotkeyPrefix);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetStringFormatTabStops(GpStringFormat *format, REAL firstTabOffset, 
                            INT count, GDIPCONST REAL *tabStops);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetStringFormatTabStops(GDIPCONST GpStringFormat *format, INT count, 
                            REAL *firstTabOffset, REAL *tabStops);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetStringFormatTabStopCount(GDIPCONST GpStringFormat *format, INT * count);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetStringFormatDigitSubstitution(GpStringFormat *format, LANGID language,
                                     GpStringDigitSubstitute substitute);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetStringFormatDigitSubstitution(GDIPCONST GpStringFormat *format, 
                                     LANGID *language,
                                     GpStringDigitSubstitute *substitute);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipGetStringFormatMeasurableCharacterRangeCount(
    GDIPCONST GpStringFormat    *format,
    INT                         *count
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetStringFormatMeasurableCharacterRanges(
    GpStringFormat              *format,
    INT                         rangeCount,
    GDIPCONST GpCharacterRange  *ranges
);

//----------------------------------------------------------------------------
// Cached Bitmap APIs
//----------------------------------------------------------------------------

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipCreateCachedBitmap(
    GpBitmap *bitmap,
    GpGraphics *graphics,
    GpCachedBitmap **cachedBitmap
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDeleteCachedBitmap(GpCachedBitmap *cachedBitmap);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipDrawCachedBitmap(
    GpGraphics *graphics,
    GpCachedBitmap *cachedBitmap,
    INT x,
    INT y
);

DECLSPEC_IMPORT UINT WINGDIPAPI
GdipEmfToWmfBits(
    HENHMETAFILE hemf,
    UINT         cbData16,
    LPBYTE       pData16,
    INT          iMapMode,
    INT          eFlags
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipSetImageAttributesCachedBackground(
    GpImageAttributes *imageattr,
    BOOL enableFlag
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipTestControl(
    GpTestControlEnum control,
    void * param
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdiplusNotificationHook(
    OUT ULONG_PTR *token
);

DECLSPEC_IMPORT VOID WINGDIPAPI
GdiplusNotificationUnhook(
    ULONG_PTR token
);

#if (GDIPVER >= 0x0110)
DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipConvertToEmfPlus(
   const GpGraphics* refGraphics,
   GpMetafile*  metafile,
   INT* conversionFailureFlag,
   GpEmfType      emfType,
   const WCHAR* description,
   GpMetafile** out_metafile
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipConvertToEmfPlusToFile(
   const GpGraphics* refGraphics,
   GpMetafile*  metafile,
   INT* conversionFailureFlag,
   const WCHAR* filename, 
   GpEmfType      emfType,
   const WCHAR* description,
   GpMetafile** out_metafile
);

DECLSPEC_IMPORT GpStatus WINGDIPAPI
GdipConvertToEmfPlusToStream(
   const GpGraphics* refGraphics,
   GpMetafile*  metafile,
   INT* conversionFailureFlag,
   IStream* stream, 
   GpEmfType      emfType,
   const WCHAR* description,
   GpMetafile** out_metafile
);
#endif //(GDIPVER >= 0x0110)

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C++" {

FORCEINLINE GpStatus WINGDIPAPI
GdipEnumerateMetafileDestPoint(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST GpPointF &    destPoint,
    GpEnumerateMetafileProc callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    )
{
    return ::GdipEnumerateMetafileDestPoint(graphics, metafile, &destPoint, callback, callbackData, imageAttributes);
}

FORCEINLINE GpStatus WINGDIPAPI
GdipEnumerateMetafileDestPointI(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST GpPoint &     destPoint,
    GpEnumerateMetafileProc callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    )
{
    return ::GdipEnumerateMetafileDestPointI(graphics, metafile, &destPoint, callback, callbackData, imageAttributes);
}

FORCEINLINE GpStatus WINGDIPAPI
GdipEnumerateMetafileDestRect(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST GpRectF &     destRect,
    GpEnumerateMetafileProc callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    )
{
    return ::GdipEnumerateMetafileDestRect(graphics, metafile, &destRect, callback, callbackData, imageAttributes);
}

FORCEINLINE GpStatus WINGDIPAPI
GdipEnumerateMetafileDestRectI(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST GpRect &      destRect,
    GpEnumerateMetafileProc callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    )
{
    return ::GdipEnumerateMetafileDestRectI(graphics, metafile, &destRect, callback, callbackData, imageAttributes);
}

FORCEINLINE GpStatus WINGDIPAPI
GdipEnumerateMetafileSrcRectDestPoint(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST GpPointF &    destPoint,
    GDIPCONST GpRectF &     srcRect,
    GpUnit                  srcUnit,
    GpEnumerateMetafileProc callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    )
{
    return ::GdipEnumerateMetafileSrcRectDestPoint(graphics, metafile, &destPoint, &srcRect, srcUnit, callback, callbackData, imageAttributes);
}

FORCEINLINE GpStatus WINGDIPAPI
GdipEnumerateMetafileSrcRectDestPointI(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST GpPoint &     destPoint,
    GDIPCONST GpRect &      srcRect,
    GpUnit                  srcUnit,
    GpEnumerateMetafileProc callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    )
{
    return ::GdipEnumerateMetafileSrcRectDestPointI(graphics, metafile, &destPoint, &srcRect, srcUnit, callback, callbackData, imageAttributes);
}

FORCEINLINE GpStatus WINGDIPAPI
GdipEnumerateMetafileSrcRectDestRect(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST GpRectF &     destRect,
    GDIPCONST GpRectF &     srcRect,
    GpUnit                  srcUnit,
    GpEnumerateMetafileProc callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    )
{
    return ::GdipEnumerateMetafileSrcRectDestRect(graphics, metafile, &destRect, &srcRect, srcUnit, callback, callbackData, imageAttributes);
}

FORCEINLINE GpStatus WINGDIPAPI
GdipEnumerateMetafileSrcRectDestRectI(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST GpRect &      destRect,
    GDIPCONST GpRect &      srcRect,
    GpUnit                  srcUnit,
    GpEnumerateMetafileProc callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    )
{
    return ::GdipEnumerateMetafileSrcRectDestRectI(graphics, metafile, &destRect, &srcRect, srcUnit, callback, callbackData, imageAttributes);
}

FORCEINLINE GpStatus WINGDIPAPI
GdipEnumerateMetafileSrcRectDestPoints(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST GpPointF *    destPoints,
    INT                     count,
    GDIPCONST GpRectF &     srcRect,
    GpUnit                  srcUnit,
    GpEnumerateMetafileProc callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    )
{
    return ::GdipEnumerateMetafileSrcRectDestPoints(graphics, metafile, destPoints, count, &srcRect, srcUnit, callback, callbackData, imageAttributes);
}

FORCEINLINE GpStatus WINGDIPAPI
GdipEnumerateMetafileSrcRectDestPointsI(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST GpPoint *     destPoints,
    INT                     count,
    GDIPCONST GpRect &      srcRect,
    GpUnit                  srcUnit,
    GpEnumerateMetafileProc callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    )
{
    return ::GdipEnumerateMetafileSrcRectDestPointsI(graphics, metafile, destPoints, count, &srcRect, srcUnit, callback, callbackData, imageAttributes);
}

FORCEINLINE GpStatus WINGDIPAPI
GdipCreateFontFromLogfont(
    HDC        hdc,
    GDIPCONST LOGFONTA  *logfont,
    GpFont   **font
)
{
    return ::GdipCreateFontFromLogfontA(hdc, logfont, font);
}

FORCEINLINE GpStatus WINGDIPAPI
GdipCreateFontFromLogfont(
    HDC        hdc,
    GDIPCONST LOGFONTW  *logfont,
    GpFont   **font
)
{
    return ::GdipCreateFontFromLogfontW(hdc, logfont, font);
}

FORCEINLINE GpStatus WINGDIPAPI
GdipGetLogFont(GpFont * font, GpGraphics *graphics, LOGFONTA * logfont)
{
    return ::GdipGetLogFontA(font, graphics, logfont);
}

FORCEINLINE GpStatus WINGDIPAPI
GdipGetLogFont(GpFont * font, GpGraphics *graphics, LOGFONTW * logfont)
{
    return ::GdipGetLogFontW(font, graphics, logfont);
}

FORCEINLINE GpStatus
WINGDIPAPI
GdipMeasureCharacterRanges(
    GpGraphics               *graphics,
    GDIPCONST WCHAR          *string,
    INT                       length,
    GDIPCONST GpFont         *font,
    GDIPCONST GpRectF        &layoutRect,
    GDIPCONST GpStringFormat *stringFormat,
    INT                       regionCount,
    GpRegion                **regions
)
{
    return ::GdipMeasureCharacterRanges(graphics, string, length, font, &layoutRect, stringFormat, regionCount, regions);
}

}
#else

FORCEINLINE GpStatus WINGDIPAPI
GdipCreateFontFromLogfont(
    HDC        hdc,
    GDIPCONST LOGFONT  *logfont,
    GpFont   **font
)
{
#ifdef UNICODE
    return GdipCreateFontFromLogfontW(hdc, logfont, font);
#else
    return GdipCreateFontFromLogfontA(hdc, logfont, font);
#endif // UNICODE
}

FORCEINLINE GpStatus WINGDIPAPI
GdipGetLogFont(GpFont * font, GpGraphics *graphics, LOGFONT * logfont)
{
#ifdef UNICODE
    return GdipGetLogFontW(font, graphics, logfont);
#else
    return GdipGetLogFontA(font, graphics, logfont);
#endif // UNICODE
}

#endif

#include <poppack.h>    // pop structure packing back to previous state

#endif // !_RAWGDIPLUS_H

