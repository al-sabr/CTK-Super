/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/

#ifndef MITKCOLORPROPERTY_H_HEADER_INCLUDED_C17953D1
#define MITKCOLORPROPERTY_H_HEADER_INCLUDED_C17953D1

#include "mitkBaseProperty.h"
#include <MitkCoreExports.h>
#include <itkRGBPixel.h>

namespace mitk
{
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4522)
#endif

  /**
   * @brief Color Standard RGB color typedef (float)
   *
   * Standard RGB color typedef to get rid of template argument (float).
   * Color range is from 0.0f to 1.0f for each component.
   *
   * @ingroup Property
   */
  typedef itk::RGBPixel<float> Color;

  /**
   * @brief The ColorProperty class RGB color property
   * @ingroup DataManagement
   *
   * @note If you want to apply the mitk::ColorProperty to an mitk::Image
   * make sure to set the mitk::RenderingModeProperty to a mode which
   * supports color (e.g. LEVELWINDOW_COLOR). For an example how to use
   * the mitk::ColorProperty see mitkImageVtkMapper2DColorTest.cpp in
   * Core/Code/Rendering.
   */
  class MITK_CORE_EXPORT ColorProperty : public BaseProperty
  {
  protected:
    mitk::Color m_Color;

    ColorProperty();

    ColorProperty(const ColorProperty &other);

    ColorProperty(const float red, const float green, const float blue);

    ColorProperty(const float color[3]);

    ColorProperty(const mitk::Color &color);

  public:
    mitkClassMacro(ColorProperty, BaseProperty);
    itkFactorylessNewMacro(Self);
    itkCloneMacro(Self) mitkNewMacro1Param(ColorProperty, const float *);
    mitkNewMacro1Param(ColorProperty, const mitk::Color &);
    mitkNewMacro3Param(ColorProperty, const float, const float, const float);

    typedef mitk::Color ValueType;

    const mitk::Color &GetColor() const;
    const mitk::Color &GetValue() const;
    std::string GetValueAsString() const override;
    void SetColor(const mitk::Color &color);
    void SetValue(const mitk::Color &color);
    void SetColor(float red, float green, float blue);

    using BaseProperty::operator=;

  private:
    // purposely not implemented
    ColorProperty &operator=(const ColorProperty &);

    itk::LightObject::Pointer InternalClone() const override;

    bool IsEqual(const BaseProperty &property) const override;
    bool Assign(const BaseProperty &property) override;
  };

#ifdef _MSC_VER
#pragma warning(pop)
#endif

} // namespace mitk

#endif /* MITKCOLORPROPERTY_H_HEADER_INCLUDED_C17953D1 */
