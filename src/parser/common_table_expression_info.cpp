#include "duckdb/parser/common_table_expression_info.hpp"
#include "duckdb/common/serializer/format_serializer.hpp"
#include "duckdb/common/serializer/format_deserializer.hpp"

namespace duckdb {

void CommonTableExpressionInfo::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty("aliases", aliases);
	serializer.WriteProperty("query", query);
}

unique_ptr<CommonTableExpressionInfo> CommonTableExpressionInfo::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = make_unique<CommonTableExpressionInfo>();
	result->aliases = deserializer.ReadProperty<vector<string>>("aliases");
	result->query = deserializer.ReadProperty<unique_ptr<SelectStatement>>("query");
	return result;
}

} // namespace duckdb
