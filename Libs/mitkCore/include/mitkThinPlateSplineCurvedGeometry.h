/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/

#ifndef MITKTHINPLATESPLINECURVEDGEOMETRY_H_HEADER_INCLUDED_C1C68A2C
#define MITKTHINPLATESPLINECURVEDGEOMETRY_H_HEADER_INCLUDED_C1C68A2C

#include "mitkLandmarkProjectorBasedCurvedGeometry.h"

class vtkPoints;
class vtkThinPlateSplineTransform;

namespace mitk
{
  //##Documentation
  //## @brief Thin-plate-spline-based landmark-based curved geometry
  //##
  //## @ingroup Geometry
  class MITK_CORE_EXPORT ThinPlateSplineCurvedGeometry : public LandmarkProjectorBasedCurvedGeometry
  {
  public:
    mitkClassMacro(ThinPlateSplineCurvedGeometry, LandmarkProjectorBasedCurvedGeometry);

    itkFactorylessNewMacro(Self);

    itkCloneMacro(Self);

      void ComputeGeometry() override;

    itk::LightObject::Pointer InternalClone() const override;

    vtkThinPlateSplineTransform *GetThinPlateSplineTransform() const { return m_ThinPlateSplineTransform; }
    virtual void SetSigma(double sigma);
    virtual double GetSigma() const;

    bool IsValid() const override;

  protected:
    ThinPlateSplineCurvedGeometry();
    ThinPlateSplineCurvedGeometry(const ThinPlateSplineCurvedGeometry &other);

    ~ThinPlateSplineCurvedGeometry() override;

    vtkThinPlateSplineTransform *m_ThinPlateSplineTransform;

    vtkPoints *m_VtkTargetLandmarks;
    vtkPoints *m_VtkProjectedLandmarks;

    //##Documentation
    //## @brief PreSetSpacing
    //##
    //## These virtual function allows a different beahiour in subclasses.
    //## Do implement them in every subclass of BaseGeometry. If not needed, use
    //## {Superclass::PreSetSpacing();};
    void PreSetSpacing(const mitk::Vector3D &aSpacing) override { Superclass::PreSetSpacing(aSpacing); };
  };
} // namespace mitk

#endif /* MITKTHINPLATESPLINECURVEDGEOMETRY_H_HEADER_INCLUDED_C1C68A2C */
