package com.github.laxsrbija.jgpscraper;

import java.io.*;
import java.util.*;
import com.github.laxsrbija.jgpscraper.locale.LocaleHelper;

public class ScraperInstance
{
	private static final String UTF_8 = "UTF-8";
	private static final String NO_DEPARTURES_SYMBOL = "q";

	private final LocaleHelper localeHelper;

	private Scanner data;
	private PrintWriter departures;
	private PrintWriter specialDepartures1;
	private PrintWriter specialDepartures2;
	private PrintWriter specialDepartures3;
	private PrintWriter specialDepartures4;

	private int firstDeparture;
	private int lastDeparture;

	public ScraperInstance(final LocaleHelper localeHelper)
	{
		this.localeHelper = localeHelper;
	}

	public void scrape(final String filename)
	{
		try
		{
			data = new Scanner(new File(filename));

			String lineName = data.next();
			System.out.println(localeHelper.getString("line-processing") + " " + lineName + ":");

			int specialDepartures = getNumberOfSpecialDepartures(data.nextInt());
			instantiateReaders(lineName, specialDepartures);

			firstDeparture = data.nextInt();
			System.out.println("\t" + localeHelper.getString("first-departure") + ": " + firstDeparture + "h");

			lastDeparture = data.nextInt();
			System.out.println("\t" + localeHelper.getString("last-departure") + ": " + lastDeparture + "h");

			final List<String> sections = Arrays.asList(
				localeHelper.getString("workday"),
				localeHelper.getString("saturday"),
				localeHelper.getString("sunday"));

			for (final String section : sections)
			{
				newSection(section);
				newLine(specialDepartures);
			}

			System.out.println("\tOK!");
		}
		catch (final FileNotFoundException | UnsupportedEncodingException e)
		{
			System.err.println(e.getMessage());
		}
		finally
		{
			close();
		}
	}

	private int getNumberOfSpecialDepartures(int specialDepartures)
	{
		final String specialDeparturesLocale = localeHelper.getString("special-departures-count");
		if (specialDepartures > 4)
		{
			specialDepartures = 4;
		}
		else if (specialDepartures < 0)
		{
			specialDepartures = 0;
		}

		System.out.println("\t" + specialDeparturesLocale + ": " + specialDepartures);
		return specialDepartures;
	}

	private void instantiateReaders(final String line, final int specialDepartures)
		throws FileNotFoundException, UnsupportedEncodingException
	{
		departures = new PrintWriter(localeHelper.getDepartures(line), UTF_8);

		if (specialDepartures >= 1)
		{
			specialDepartures1 = new PrintWriter(localeHelper.getSpecialDepartures(line, 1), UTF_8);
		}

		if (specialDepartures >= 2)
		{
			specialDepartures2 = new PrintWriter(localeHelper.getSpecialDepartures(line, 2), UTF_8);
		}

		if (specialDepartures >= 3)
		{
			specialDepartures3 = new PrintWriter(localeHelper.getSpecialDepartures(line, 3), UTF_8);
		}

		if (specialDepartures == 4)
		{
			specialDepartures4 = new PrintWriter(localeHelper.getSpecialDepartures(line, 4), UTF_8);
		}
	}

	private void newLine(int specialDeparturesCount)
	{
		departures.println();
		if (specialDeparturesCount >= 1)
		{
			specialDepartures1.println();
		}
		if (specialDeparturesCount >= 2)
		{
			specialDepartures2.println();
		}
		if (specialDeparturesCount >= 3)
		{
			specialDepartures3.println();
		}
		if (specialDeparturesCount == 4)
		{
			specialDepartures4.println();
		}
	}

	private void newSection(final String sectionName)
	{
		final String value = sectionName + ":";
		if (departures != null)
		{
			departures.println(value);
		}
		if (specialDepartures1 != null)
		{
			specialDepartures1.println(value);
		}
		if (specialDepartures2 != null)
		{
			specialDepartures2.println(value);
		}
		if (specialDepartures3 != null)
		{
			specialDepartures3.println(value);
		}
		if (specialDepartures4 != null)
		{
			specialDepartures4.println(value);
		}

		processDepartures();
	}

	private void processDepartures()
	{
		int currentHour = firstDeparture;
		while (currentHour <= lastDeparture && data.hasNext())
		{
			final String entry = data.nextLine();

			if (entry.trim().isEmpty())
			{
				continue;
			}

			// We are skipping the current hour
			if (entry.equalsIgnoreCase(NO_DEPARTURES_SYMBOL))
			{
				++currentHour;
				continue;
			}

			final String[] split = entry.split(",");
			for (final String departure : split)
			{
				final String minute = departure.replaceAll("[^0-9]", "");
				final String departureString = generateDepartureValue(currentHour, minute);

				if (departure.contains("****"))
				{
					specialDepartures4.println(departureString);
				}
				else if (departure.contains("***"))
				{
					specialDepartures3.println(departureString);
				}
				else if (departure.contains("**"))
				{
					specialDepartures2.println(departureString);
				}
				else if (departure.contains("*"))
				{
					specialDepartures1.println(departureString);
				}
				else
				{
					departures.println(departureString);
				}
			}

			++currentHour;
		}
	}

	private String generateDepartureValue(final int hour, final String minute)
	{
		final String satPrefix = hour >= 10 ? "" : "0";
		return satPrefix + hour + ":" + minute;
	}

	private void close()
	{
		if (data != null)
		{
			data.close();
		}

		if (departures != null)
		{
			departures.close();
		}

		if (specialDepartures1 != null)
		{
			specialDepartures1.close();
		}

		if (specialDepartures2 != null)
		{
			specialDepartures2.close();
		}

		if (specialDepartures3 != null)
		{
			specialDepartures3.close();
		}

		if (specialDepartures4 != null)
		{
			specialDepartures4.close();
		}
	}
}
