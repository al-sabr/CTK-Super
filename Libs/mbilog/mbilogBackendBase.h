/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/

#ifndef _mbilogBackendBase_H
#define _mbilogBackendBase_H

#include "mbilogExport.h"
#include "mbilogLogMessage.h"

namespace mbilog
{
  /**
   * This enum defines the type of the output of a backend.
   * Console: output generated to the console
   * File: output generated to a file
   * Other: all other kinds of output
   */
  enum MBILOG_EXPORT OutputType
  {
    Console = 0,
    File,
    Other = 100
  };
  /**
   *  \brief This class is an interface for logging backends that can be registered in the mbi logging mechanism.
   *
   *  \ingroup mbilog
   */
  class MBILOG_EXPORT BackendBase
  {
  public:
    virtual ~BackendBase();

    /**
     * \brief This method is called by the mbi logging mechanism if the object is registered in
     *         the mbi logging mechanism and a logging message is emitted.
     *
     * \param logMessage Logging message which was emitted.
     *
     */
    virtual void ProcessMessage(const mbilog::LogMessage &logMessage) = 0;

    /**
     * @return The type of this backend.
     */
    virtual OutputType GetOutputType() const = 0;
  };
}

#endif
