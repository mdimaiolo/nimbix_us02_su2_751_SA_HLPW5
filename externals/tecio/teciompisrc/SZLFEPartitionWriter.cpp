#include "SZLFEPartitionWriter.h"
#include "ThirdPartyHeadersBegin.h"
#include <sstream>
#include "ThirdPartyHeadersEnd.h"
#include "FEZoneInfo.h"
#include "writeValueArray.h"
namespace tecplot { namespace ___3933 { class ItemSetIterator; SZLFEPartitionWriter::SZLFEPartitionWriter( ItemSetIterator&                    varIter, ___4636                         zone, ___4636                         ASSERT_ONLY(___341), ___2090::___2980            ___2977, std::vector<___372> const&       ___4564, ___372                           ___4499, ___37&                         ___36, boost::shared_ptr<___1350 const> zoneInfo) : SZLFEZoneWriter(varIter, static_cast<___4636>(___2977), 0, ___4564, ___4499, ___36, zoneInfo) { REQUIRE(0 <= ___341 && ___341 <= zone); std::ostringstream labelStream; labelStream << "partitionNumForZone" << zone + 1 << "*"; std::ostringstream suffixStream; suffixStream << "ForZone" << zone + 1 << "Partition"; m_headerWriter.setMarkerAndLabels("partitionMarker*", SZPLT_PARTITION_MARKER, labelStream.str(), suffixStream.str()); setZoneNumberLabel(labelStream.str()); } SZLFEPartitionWriter::~SZLFEPartitionWriter() {} ___2479 SZLFEPartitionWriter::varMinMax(___4352 ___4336) { ___2479 minMax = ___4709::varMinMax(___4336); ___1350::NszMinMaxMap const& nszMinMaxMap = m_feZoneInfo->getNszMinMaxes(); for (___1350::NszMinMaxMap::const_iterator it = nszMinMaxMap.begin(); it != nszMinMaxMap.end(); ++it) minMax.include(it->second[___4336]); return minMax; } } }