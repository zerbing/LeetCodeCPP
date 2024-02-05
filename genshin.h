#pragma once

namespace genshin
{
const double kRelicsCriticalRate = 0.0333333;
const double kRelicsCriticalDamage = 0.0666667;
const double kRelicsAttack = 0.05;
const double kRelicsHealth = 0.05;
const double kRelicsDefence = 0.0625;
const double kRelicsElementalMastery = 19.8;
const double kRelicsEnergyRecharge = 0.0556667;

// 元素精通增幅反应加成公式
double ElementalMasteryAmpedFormula(int elemental_mastery);
} // namespace genshin