#include "BaseWidget.h"

void UBaseWidget::SetVisibility(ESlateVisibility InVisibility)
{
	Super::SetVisibility(InVisibility);

	VisibilityChanged(InVisibility);
}
