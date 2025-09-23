// Copyright KroNus Games 2025


#include "Public/UI/Widget/ShUserWidget.h"

void UShUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
