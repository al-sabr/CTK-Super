/*=========================================================================

  Library:   CTK

  Copyright (c) PerkLab 2013

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=========================================================================*/

#ifndef __ctkDICOMDisplayedFieldGeneratorRadiotherapySeriesDescriptionRule_h
#define __ctkDICOMDisplayedFieldGeneratorRadiotherapySeriesDescriptionRule_h

// Qt includes
#include <QStringList>

#include "ctkDICOMDisplayedFieldGeneratorAbstractRule.h"

/// \ingroup DICOM_Core
///
/// Special rule for generating series description displayed fields for different RT modalities
class CTK_DICOM_CORE_EXPORT ctkDICOMDisplayedFieldGeneratorRadiotherapySeriesDescriptionRule : public ctkDICOMDisplayedFieldGeneratorAbstractRule
{
public:
  /// Constructor
  explicit ctkDICOMDisplayedFieldGeneratorRadiotherapySeriesDescriptionRule();

  /// Specify list of DICOM tags required by the rule. These tags will be included in the tag cache
  virtual QStringList getRequiredDICOMTags();

  /// Register placeholder strings that still mean that a given field can be considered empty.
  /// Used when merging the original database content with the displayed fields generated by the rules.
  /// Example: SeriesDescription -> Unnamed Series
  virtual void registerEmptyFieldNames(QMap<QString, QString> emptyFieldsSeries, QMap<QString, QString> emptyFieldsStudies, QMap<QString, QString> emptyFieldsPatients);

  /// Generate displayed fields for a certain instance based on its cached tags
  /// The way these generated fields will be used is defined by \sa mergeDisplayedFieldsForInstance
  virtual void getDisplayedFieldsForInstance(
    const QMap<QString, QString> &cachedTagsForInstance, QMap<QString, QString> &displayedFieldsForCurrentSeries,
    QMap<QString, QString> &displayedFieldsForCurrentStudy, QMap<QString, QString> &displayedFieldsForCurrentPatient );

  /// Define rules of merging initial database values with new values generated by the rule plugins
  virtual void mergeDisplayedFieldsForInstance(
    const QMap<QString, QString> &initialFieldsSeries, const QMap<QString, QString> &initialFieldsStudy, const QMap<QString, QString> &initialFieldsPatient,
    const QMap<QString, QString> &newFieldsSeries, const QMap<QString, QString> &newFieldsStudy, const QMap<QString, QString> &newFieldsPatient,
    QMap<QString, QString> &mergedFieldsSeries, QMap<QString, QString> &mergedFieldsStudy, QMap<QString, QString> &mergedFieldsPatient,
    const QMap<QString, QString> &emptyFieldsSeries, const QMap<QString, QString> &emptyFieldsStudy, const QMap<QString, QString> &emptyFieldsPatient );

protected:
  const QString EmptySeriesDescriptionRtPlan;
  const QString EmptySeriesDescriptionRtStruct;
  const QString EmptySeriesDescriptionRtImage;
};

#endif
