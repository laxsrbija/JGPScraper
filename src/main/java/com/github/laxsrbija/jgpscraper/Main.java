package com.github.laxsrbija.jgpscraper;

public class Main
{
	public static void main(final String[] args)
	{
		final String language = args.length > 0 ? args[0] : "sr";

		final Scraper scraper = new Scraper(language);
		scraper.scrape();
	}
}
