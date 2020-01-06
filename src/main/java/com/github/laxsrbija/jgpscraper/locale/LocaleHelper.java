package com.github.laxsrbija.jgpscraper.locale;

import java.util.Locale;
import java.util.ResourceBundle;

public class LocaleHelper
{
	private static final String OUTPUT_EXTENSION = ".txt";

	private final ResourceBundle bundle;

	public LocaleHelper(final String localeString)
	{
		final Locale locale = new Locale(localeString);
		bundle = ResourceBundle.getBundle("messages", locale);
	}

	public String getString(String key)
	{
		return bundle.getString(key);
	}

	public String getDepartures(final String line)
	{
		final String departures = bundle.getString("departures-filename");
		return line + " - " + departures + OUTPUT_EXTENSION;
	}

	public String getSpecialDepartures(final String line, final int variant)
	{
		final String specialDepartures = bundle.getString("special-departures-filename");
		return line + " - " + specialDepartures + " " + variant + OUTPUT_EXTENSION;
	}
}
