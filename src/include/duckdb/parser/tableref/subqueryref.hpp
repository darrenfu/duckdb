//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/parser/tableref/subqueryref.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/parser/statement/select_statement.hpp"
#include "duckdb/parser/tableref.hpp"

namespace duckdb {
//! Represents a subquery
class SubqueryRef : public TableRef {
public:
	DUCKDB_API explicit SubqueryRef(unique_ptr<SelectStatement> subquery, string alias = string());

	//! The subquery
	unique_ptr<SelectStatement> subquery;
	//! Aliases for the column names
	vector<string> column_name_alias;

public:
	string ToString() const override;
	bool Equals(const TableRef *other_p) const override;

	unique_ptr<TableRef> Copy() override;

	//! Serializes a blob into a SubqueryRef
	void Serialize(FieldWriter &serializer) const override;
	//! Deserializes a blob back into a SubqueryRef
	static unique_ptr<TableRef> Deserialize(FieldReader &source);

	void FormatSerialize(FormatSerializer &serializer) const override;
	static unique_ptr<TableRef> FormatDeserialize(FormatDeserializer &source);
};
} // namespace duckdb
