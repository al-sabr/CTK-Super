/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/

#ifndef GEOMETRY3D_H_HEADER_INCLUDED_C1EBD0AD
#define GEOMETRY3D_H_HEADER_INCLUDED_C1EBD0AD

#include "mitkNumericTypes.h"
#include <MitkCoreExports.h>
#include <mitkCommon.h>

#include "itkScalableAffineTransform.h"
#include <itkIndex.h>

#include "mitkBaseGeometry.h"

class vtkLinearTransform;

namespace mitk
{
  /** @brief Standard implementation of BaseGeometry.
    * @ingroup Geometry
    */
  class MITK_CORE_EXPORT Geometry3D : public BaseGeometry
  {
  public:
    mitkClassMacro(Geometry3D, mitk::BaseGeometry);

    typedef itk::QuaternionRigidTransform<ScalarType> QuaternionTransformType;
    typedef QuaternionTransformType::VnlQuaternionType VnlQuaternionType;

    /** Method for creation through the object factory. */
    itkFactorylessNewMacro(Self);
    mitkNewMacro1Param(Self, const Self&);

    itkCloneMacro(Self);

  protected : Geometry3D();
    Geometry3D(const Geometry3D &);

    /**
      * @brief clones the geometry
      *
      * Overwrite in all sub-classes.
      * Normally looks like:
      * \code
      *  Self::Pointer newGeometry = new Self(*this);
      *  newGeometry->UnRegister();
      *  return newGeometry.GetPointer();
      * \endcode
      */
    itk::LightObject::Pointer InternalClone() const override;

    ~Geometry3D() override;

    /**
      * @brief PreSetSpacing
      *
      * These virtual function allows a different beahiour in subclasses.
      * Do implement them in every subclass of BaseGeometry. If not needed, use
      * \c Superclass::PreSetSpacing().
      */
    void PreSetSpacing(const mitk::Vector3D &aSpacing) override { Superclass::PreSetSpacing(aSpacing); };
  };
} // namespace mitk

#endif /* GEOMETRY3D_H_HEADER_INCLUDED_C1EBD0AD */
