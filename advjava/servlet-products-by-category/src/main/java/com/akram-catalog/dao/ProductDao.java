package com.catalog.dao;
import java.sql.SQLException;
import java.util.List;

import com.catalog.entities.*;

public interface ProductDao extends BaseDao {
	List<Product> getAllProducts(long category_id) throws SQLException;
}
