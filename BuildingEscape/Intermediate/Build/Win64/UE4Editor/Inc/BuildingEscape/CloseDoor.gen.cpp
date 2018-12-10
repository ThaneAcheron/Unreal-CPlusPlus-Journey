// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BuildingEscape/CloseDoor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCloseDoor() {}
// Cross Module References
	BUILDINGESCAPE_API UClass* Z_Construct_UClass_UCloseDoor_NoRegister();
	BUILDINGESCAPE_API UClass* Z_Construct_UClass_UCloseDoor();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_BuildingEscape();
// End Cross Module References
	void UCloseDoor::StaticRegisterNativesUCloseDoor()
	{
	}
	UClass* Z_Construct_UClass_UCloseDoor_NoRegister()
	{
		return UCloseDoor::StaticClass();
	}
	struct Z_Construct_UClass_UCloseDoor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCloseDoor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_BuildingEscape,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCloseDoor_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "CloseDoor.h" },
		{ "ModuleRelativePath", "CloseDoor.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCloseDoor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCloseDoor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCloseDoor_Statics::ClassParams = {
		&UCloseDoor::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x00B000A4u,
		nullptr, 0,
		nullptr, 0,
		"Engine",
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UCloseDoor_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UCloseDoor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCloseDoor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCloseDoor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCloseDoor, 454126325);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCloseDoor(Z_Construct_UClass_UCloseDoor, &UCloseDoor::StaticClass, TEXT("/Script/BuildingEscape"), TEXT("UCloseDoor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCloseDoor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
