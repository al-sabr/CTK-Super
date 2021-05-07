/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/

#ifndef SUBIMAGESELECTOR_H_HEADER_INCLUDED_C1E4F463
#define SUBIMAGESELECTOR_H_HEADER_INCLUDED_C1E4F463

#include "mitkBaseData.h"
#include "mitkImageDataItem.h"
#include "mitkImageToImageFilter.h"
#include <MitkCoreExports.h>

namespace mitk
{
  //##Documentation
  //## @brief Base class of all classes providing access to parts of an image
  //##
  //## Base class of all classes providing access to parts of an image, e.g., to
  //## a slice (mitk::ImageSilceSelector) or a volume at a specific time
  //## (mitk::ImageTimeSelector). If the input is generated by a ProcessObject,
  //## only the required data is requested.
  //## @ingroup Process
  class MITK_CORE_EXPORT SubImageSelector : public ImageToImageFilter
  {
  public:
    /** Run-time type information (and related methods). */
    mitkClassMacro(SubImageSelector, ImageToImageFilter);

    itkFactorylessNewMacro(Self);

    itkCloneMacro(Self);

      virtual void SetPosNr(int p);

    SubImageSelector();

    ~SubImageSelector() override;

  protected:
    mitk::Image::ImageDataItemPointer GetSliceData(int s = 0, int t = 0, int n = 0);
    mitk::Image::ImageDataItemPointer GetVolumeData(int t = 0, int n = 0);
    mitk::Image::ImageDataItemPointer GetChannelData(int n = 0);

    void SetSliceItem(mitk::Image::ImageDataItemPointer dataItem, int s = 0, int t = 0, int n = 0);
    void SetVolumeItem(mitk::Image::ImageDataItemPointer dataItem, int t = 0, int n = 0);
    void SetChannelItem(mitk::Image::ImageDataItemPointer dataItem, int n = 0);
  };

} // namespace mitk

#endif /* SUBIMAGESELECTOR_H_HEADER_INCLUDED_C1E4F463 */
