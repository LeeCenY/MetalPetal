//
//  MTICornerRadius.h
//  Pods
//
//  Created by YuAo on 2021/4/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

struct MTICornerRadius {
    float topLeft;
    float topRight;
    float bottomRight;
    float bottomLeft;
};
typedef struct MTICornerRadius MTICornerRadius;

typedef NS_ENUM(NSInteger, MTICornerCurve) {
    /// A circular corner curve.
    MTICornerCurveCircular = 0,
    
    /// A continuous corner curve. This option mimics the behavior of `kCACornerCurveContinuous`.
    MTICornerCurveContinuous = 1
};

FOUNDATION_STATIC_INLINE __attribute__((__overloadable__)) NS_SWIFT_UNAVAILABLE("Use MTICornerRadius.init(topLeft:topRight:bottomRight:bottomLeft:)") MTICornerRadius MTICornerRadiusMake(float topLeft, float topRight, float bottomRight, float bottomLeft){
    MTICornerRadius radius;
    radius.topLeft = topLeft;
    radius.topRight = topRight;
    radius.bottomRight = bottomRight;
    radius.bottomLeft = bottomLeft;
    return radius;
}

FOUNDATION_STATIC_INLINE __attribute__((__overloadable__)) NS_SWIFT_NAME(MTICornerRadius.init(_:)) MTICornerRadius MTICornerRadiusMake(float r) {
    MTICornerRadius radius;
    radius.topLeft = r;
    radius.topRight = r;
    radius.bottomRight = r;
    radius.bottomLeft = r;
    return radius;
}

FOUNDATION_STATIC_INLINE NS_SWIFT_NAME(getter:MTICornerRadius.isZero(self:)) BOOL MTICornerRadiusIsZero(MTICornerRadius r) {
    return r.topLeft == 0 && r.topRight == 0 && r.bottomLeft == 0 && r.bottomRight == 0;
}

/// Expansion scale factor applied to the rounded corner bounding box size when specific corner curve is used.
FOUNDATION_STATIC_INLINE NS_SWIFT_NAME(getter:MTICornerCurve.expansionFactor(self:)) float MTICornerCurveExpansionFactor(MTICornerCurve curve) {
    switch (curve) {
        case MTICornerCurveCircular:
            return 1.0;
        case MTICornerCurveContinuous:
            return 1.528665;
        default:
            return 1;
    }
}

FOUNDATION_STATIC_INLINE simd_float4 _MTICornerRadiusGetShadingParameterValue(MTICornerRadius r, MTICornerCurve curve) {
    simd_float4 radius = simd_make_float4(r.topLeft, r.topRight, r.bottomRight, r.bottomLeft);
    return radius * MTICornerCurveExpansionFactor(curve);
}

NS_ASSUME_NONNULL_END
