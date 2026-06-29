package com.catalog.dao;
import java.sql.SQLException;
import java.util.List;

import com.catalog.entities.*;

public interface CategoryDao extends BaseDao {
	List<Category> getCategoryList() throws SQLException;
}
