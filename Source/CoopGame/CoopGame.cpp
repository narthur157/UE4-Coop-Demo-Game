// Fill out your copyright notice in the Description page of Project Settings.

#include "CoopGame.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, CoopGame, "CoopGame" );


DEFINE_LOG_CATEGORY(CATSpawning);
DEFINE_LOG_CATEGORY(CATGeneralActions);
DEFINE_LOG_CATEGORY(CATDamage);
DEFINE_LOG_CATEGORY(CATNetLog);