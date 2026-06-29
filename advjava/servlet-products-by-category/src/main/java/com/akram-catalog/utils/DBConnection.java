package com.catalog.utils;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBUtils {
	private final static String dbURL = "jdbc:mysql://localhost:3306/servlet-products-by-category";
	private final static String userName = "kd3_akram_96232";
	private final static String password = "akram";
	
	public static Connection getConnection() throws SQLException
	{
		return DriverManager.getConnection(dbURL, userName, password);
	}
}
