package com.github.laxsrbija.jgpscraper;

import java.util.Scanner;
import com.github.laxsrbija.jgpscraper.locale.LocaleHelper;

public class Scraper
{
	private final LocaleHelper localeHelper;

	public Scraper(final String locale)
	{
		localeHelper = new LocaleHelper(locale);
	}

	public void scrape()
	{
		final Scanner scanner = new Scanner(System.in);

		System.out.println("       _  _____ _____   _____                                \n"
			+ "      | |/ ____|  __ \\ / ____|                               \n"
			+ "      | | |  __| |__) | (___   ___ _ __ __ _ _ __   ___ _ __ \n"
			+ "  _   | | | |_ |  ___/ \\___ \\ / __| '__/ _` | '_ \\ / _ \\ '__|\n"
			+ " | |__| | |__| | |     ____) | (__| | | (_| | |_) |  __/ |   \n"
			+ "  \\____/ \\_____|_|    |_____/ \\___|_|  \\__,_| .__/ \\___|_|   \n"
			+ "                                            | |              \n"
			+ "          https://github.com/laxsrbija      |_|              ");

		do
		{
			final ScraperInstance scraperInstance = new ScraperInstance(this.localeHelper);

			System.out.println("\n" + localeHelper.getString("enter-filename") + ": ");
			final String inputFilename = scanner.nextLine();
			scraperInstance.scrape(inputFilename);

			System.out.println(localeHelper.getString("continue") + " (y/N)?");
		} while ("y".equalsIgnoreCase(scanner.nextLine()));

		scanner.close();
	}
}
