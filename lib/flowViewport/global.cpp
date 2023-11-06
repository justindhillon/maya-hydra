// Copyright 2023 Autodesk
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "global.h"

#include <flowViewport/colorPreferences/fvpColorPreferences.h>

namespace FVP_NS_DEF {

void initialize(const InitializationParams& params)
{
    params.colorPreferencesNotificationProvider->addObserver(
        Fvp::ColorPreferences::getInstance().shared_from_this());
    Fvp::ColorPreferences::getInstance().setTranslator(params.colorPreferencesTranslator);
}

void finalize(const InitializationParams& params)
{
    params.colorPreferencesNotificationProvider->removeObserver(
        Fvp::ColorPreferences::getInstance().shared_from_this());
    Fvp::ColorPreferences::getInstance().setTranslator(nullptr);

    Fvp::ColorPreferences::deleteInstance();
}

} // namespace FVP_NS_DEF
