// Fill out your copyright notice in the Description page of Project Settings.

#include "PulseMaterialEffect.h"

PulseMaterialEffect::PulseMaterialEffect()
{
}

void PulseMaterialEffect::SetParams(UMaterialInstanceDynamic* MatInstance, float Intensity /*= 0.0f*/, FColor Color /*= FColor::White*/, float Frequency /*= 1.0f*/)
{
	MatInstance->SetScalarParameterValue("PulseFreq", Frequency);
	MatInstance->SetScalarParameterValue("PulseIntensity", Intensity);
	MatInstance->SetVectorParameterValue("GlowColor", Color);
}

PulseMaterialEffect::~PulseMaterialEffect()
{
}
