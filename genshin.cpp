#include "pch.h"
#include "genshin.h"

namespace genshin
{
double genshin::ElementalMasteryAmpedFormula(int elemental_mastery)
{
  return 2.78 * elemental_mastery / (elemental_mastery + 1400);
}
}