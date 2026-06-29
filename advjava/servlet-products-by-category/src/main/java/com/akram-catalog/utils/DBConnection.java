package com.catalog.utils;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBUtils {
	private final static String dbURL = "jdbc:mysql://localhost:3306/product_catalog";
	private final static String userName = "root";
	private final static String password = "manager";
	
	public static Connection getConnection() throws SQLException
	{
		return DriverManager.getConnection(dbURL, userName, password);
	}
}
