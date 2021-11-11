#pragma once

/** Helper utils for working with geometry queries from C++ with built-in debug draw functionality. 
 * Created since analogous UKismetSystemLibrary utils causes additional performance overhead of collision channel casting
 */
namespace GCTraceUtils
{
	/** Sweep single (till first blocking hit) capsule by chanel
	 * @param World - trace world
	 * @param OutHit - output for detected hit result
	 * @return true if query is successful, false otherwise
	 */
	bool SweepCapsuleSingleByChanel(const UWorld* World, struct FHitResult& OutHit, const FVector& Start, const FVector& End, float CapsuleRadius, float CapsuleHalfHeight, const FQuat& Rot, ECollisionChannel TraceChannel, const FCollisionQueryParams& Params = FCollisionQueryParams::DefaultQueryParam, const FCollisionResponseParams& ResponseParam = FCollisionResponseParams::DefaultResponseParam, bool bDrawDebug = false, float DrawTime = -1.0f, FColor TraceColor = FColor::Black, FColor HitColor = FColor::Red);
	/** 
	 */
	bool SweepSphereSingleByChanel(const UWorld* World, struct FHitResult& OutHit, const FVector& Start, const FVector& End, float Radius, ECollisionChannel TraceChannel, const FCollisionQueryParams& Params = FCollisionQueryParams::DefaultQueryParam, const FCollisionResponseParams& ResponseParam = FCollisionResponseParams::DefaultResponseParam, bool bDrawDebug = false, float DrawTime = -1.0f, FColor TraceColor = FColor::Black, FColor HitColor = FColor::Red);

	bool OverlapCapusleAnyByProfile(const UWorld* World, const FVector& Pos, float CapsuleRadius, float CapsuleHalfHeight, FQuat Rotation, FName ProfileName, const FCollisionQueryParams& QueryParams, bool bDrawDebug = false, float DrawTime = -1.0f, FColor HitColor = FColor::Red);
	bool OverlapCapusleBlockingByProfile(const UWorld* World, const FVector& Pos, float CapsuleRadius, float CapsuleHalfHeight, FQuat Rotation, FName ProfileName, const FCollisionQueryParams& QueryParams, bool bDrawDebug = false, float DrawTime = -1.0f, FColor HitColor = FColor::Red);
}

