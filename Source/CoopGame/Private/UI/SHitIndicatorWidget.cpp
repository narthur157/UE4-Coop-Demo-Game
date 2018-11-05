#include "SHitIndicatorWidget.h"
#include "Animation/WidgetAnimation.h"

void USHitIndicatorWidget::PlayHitAnimation()
{
	UE_LOG(LogTemp, Error, TEXT("Hit animation!"));

	if (FadeAnimation)
	{
		UE_LOG(LogTemp, Error, TEXT("Hit animation!2"));
		PlayAnimation(FadeAnimation);
	}
}
