// Copyright KroNus Games 2025


#include "ShGameplayTags.h"

namespace ShGameplayTags{
	namespace Attributes
	{
		namespace Primary
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Strength, "Attributes.Primary.Strength", "Increases physical power and melee impact.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Toughness, "Attributes.Primary.Toughness", "Improves resistance and overall durability.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Dexterity, "Attributes.Primary.Dexterity", "Enhances agility, precision, and handling.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Intelligence, "Attributes.Primary.Intelligence", "Boosts tech efficiency and ability power.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Charisma, "Attributes.Primary.Charisma", "Influences persuasion and NPC interaction.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Perception, "Attributes.Primary.Perception", "Improves awareness, accuracy, and detection.");
		}
		namespace Secondary
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Health, "Attributes.Secondary.Health", "Amount of life available.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxHealth, "Attributes.Secondary.MaxHealth", "Maximum amount of life available.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Armor, "Attributes.Secondary.Armor", "Absorbs incoming damage temporarily.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxArmor, "Attributes.Secondary.MaxArmor", "Maximum armor capacity.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxStamina, "Attributes.Secondary.MaxStamina", "Maximum stamina capacity.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Stamina, "Attributes.Secondary.Stamina", "Amount of energy available.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(PowerCore, "Attributes.Secondary.PowerCore", "Energy used for abilities or tech actions.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxPowerCore, "Attributes.Secondary.MaxPowerCore", "Maximum PowerCore capacity.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Mobility, "Attributes.Secondary.Mobility", "Affects movement speed and agility.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxMobility, "Attributes.Secondary.MaxMobility", "Maximum movement speed and agility.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Damage, "Attributes.Secondary.Damage", "Base damage output for attacks.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(CriticalChance, "Attributes.Secondary.CriticalChance", "Chance to deal a critical hit.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(CriticalDamage, "Attributes.Secondary.CriticalDamage", "Bonus damage when landing a critical hit.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(HealthRegen, "Attributes.Secondary.HealthRegen", "Rate at which health recovers over time.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(StaminaRegen, "Attributes.Secondary.StaminaRegen", "Rate at which stamina restores.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(PowerRegen, "Attributes.Secondary.PowerCoreRegen", "Rate at which power core restores.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Hunger, "Attributes.Secondary.Hunger", "Current hunger level affecting survival.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxHunger, "Attributes.Secondary.MaxHunger", "Maximum hunger resistance capacity.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Thirst, "Attributes.Secondary.Thirst", "Current dehydration level.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxThirst, "Attributes.Secondary.MaxThirst", "Maximum thirst resistance capacity.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Fatigue, "Attributes.Secondary.Fatigue", "Accumulated exhaustion over time.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxFatigue, "Attributes.Secondary.MaxFatigue", "Maximum fatigue tolerance.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Stress, "Attributes.Secondary.Stress", "Mental pressure affecting performance.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxStress, "Attributes.Secondary.MaxStress", "Maximum stress tolerance.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Contamination, "Attributes.Secondary.Contamination", "Level of biological or radiation exposure.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxContamination, "Attributes.Secondary.MaxContamination", "Maximum contamination tolerance.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Processing, "Attributes.Secondary.Processing", "Active computational power available.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxProcessing, "Attributes.Secondary.MaxProcessing", "Maximum processing capacity.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(LoyaltyProtocol, "Attributes.Secondary.LoyaltyProtocol", "AI obedience and trust level.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxLoyaltyProtocol, "Attributes.Secondary.MaxLoyaltyProtocol", "Maximum loyalty protocol stability.");
		}
	}
	namespace InputTag
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(KeyboardNumber1, "InputTag.KeyboardNumber1", "Keyboard number 1.");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(KeyboardNumber2, "InputTag.KeyboardNumber2", "Keyboard number 2.");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(KeyboardNumber3, "InputTag.KeyboardNumber3", "Keyboard number 3.");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(KeyboardNumber4, "InputTag.KeyboardNumber4", "Keyboard number 4.");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(KeyboardNumber5, "InputTag.KeyboardNumber5", "Keyboard number 5.");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(KeyboardNumber6, "InputTag.KeyboardNumber6", "Keyboard number 6.");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(KeyboardNumber7, "InputTag.KeyboardNumber7", "Keyboard number 7.");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(KeyboardNumber8, "InputTag.KeyboardNumber8", "Keyboard number 8");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(KeyboardNumber9, "InputTag.KeyboardNumber9", "Keyboard number 9.");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(KeyboardNumber10, "InputTag.KeyboardNumber10", "Keyboard number 0");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(KeyboardNumber11, "InputTag.KeyboardNumber11", "Keyboard number '.");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(KeyboardNumber12, "InputTag.KeyboardNumber12", "Keyboard number ¡.");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(LeftMouseButton, "InputTag.LeftMouseButton", "Left mouse button.");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(RightMouseButton, "InputTag.RightMouseButton", "Right mouse button.");
	}
	namespace Data
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(HealAmount, "Attributes.Data.HealAmount", "Amount of health restored.");
	}
}
