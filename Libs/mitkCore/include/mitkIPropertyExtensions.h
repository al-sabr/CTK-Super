/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/

#ifndef mitkIPropertyExtensions_h
#define mitkIPropertyExtensions_h

#include <MitkCoreExports.h>
#include <mitkPropertyExtension.h>
#include <mitkServiceInterface.h>
#include <string>

namespace mitk
{
  /**
   * \ingroup MicroServices_Interfaces
   * \brief Interface of property extensions service.
   *
   * This service allows you to manage extensions for properties.
   * An extension is a class that derives from mitk::PropertyExtension.
   * Use extensions to attach useful metadata to your properties, e.g. the allowed range of values.
   * Note that you have to extend the property view if you want it to respect your custom metadata.
   */
  class MITK_CORE_EXPORT IPropertyExtensions
  {
  public:
    virtual ~IPropertyExtensions();

    /** \brief Add an extension to a specific property.
      *
      * \param[in] propertyName Name of the property.
      * \param[in] extension Property extension.
      * \param[in] className Optional data node class name to which the property extension is restricted.
      * \param[in] overwrite Overwrite already existing property extension.
      * \return True if extension was added successfully.
      */
    virtual bool AddExtension(const std::string &propertyName,
                              PropertyExtension::Pointer extension,
                              const std::string &className = "",
                              bool overwrite = false) = 0;

    /** \brief Get the extension of a specific property.
      *
      * \param[in] propertyName Name of the property.
      * \param[in] className Optional data node class name to which the returned property extension is restricted.
      * \return Property extension or null pointer if no extension was found.
      */
    virtual PropertyExtension::Pointer GetExtension(const std::string &propertyName,
                                                    const std::string &className = "") = 0;

    /** \brief Check if a specific property has an extension.
      *
      * \param[in] propertyName Name of the property.
      * \param[in] className Optional data node class name to which the property extension is restricted.
      * \return True if the property has an extension, false otherwise.
      */
    virtual bool HasExtension(const std::string &propertyName, const std::string &className = "") = 0;

    /** \brief Remove all property extensions.
      *
      * \param[in] className Optional data node class name to which the property extension is restricted.
      */
    virtual void RemoveAllExtensions(const std::string &className = "") = 0;

    /** \brief Remove extension of a specific property.
      *
      * \param[in] propertyName Name of the property.
      * \param[in] className Optional data node class name to which the property extension is restricted.
      */
    virtual void RemoveExtension(const std::string &propertyName, const std::string &className = "") = 0;
  };
}

US_DECLARE_SERVICE_INTERFACE(mitk::IPropertyExtensions, "org.mitk.IPropertyExtensions")

#endif
