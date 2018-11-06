#include "SHitIndicatorWidget.h"
#include "Animation/WidgetAnimation.h"

void USHitIndicatorWidget::PlayHitAnimation()
{
	if (FadeAnimation)
	{
		PlayAnimation(FadeAnimation);
	}
}
