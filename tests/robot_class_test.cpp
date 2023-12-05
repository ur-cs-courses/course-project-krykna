#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <catch.hpp>
#include "libRobot/Robot.hpp"

TEST_CASE("Independent Class: Robot") {
    SECTION("Concentation: Robot Default Constructor") {
        Robot bot;
        REQUIRE(bot.to_string_status() == "Status:\tBusy");
        REQUIRE(bot.to_string_size() == "Size:\tMedium");
        REQUIRE(bot.to_string_type() == "Type:\tVaccuum");
        REQUIRE(bot.get_room() == "");
    }

    SECTION("Concentration: Robot Constructor") {
        Robot bot("0", "free", "small", "vac", "3");
        REQUIRE(bot.to_string_status() == "Status:\tBusy");
        REQUIRE(bot.to_string_size() == "Size:\tSmall");
        REQUIRE(bot.to_string_type() == "Type:\tVaccuum");
        REQUIRE(bot.get_room() == "3");
    }

    SECTION("Concentration: Robot Status") { 
        // COMING SOON: needs to be updated
        Robot free("NA", "Free", "NA", "NA", "NA");
        Robot edgecase_free("NA", "free", "NA", "NA", "NA");
        REQUIRE(free.to_string_status() == "Status:\tFree");
        REQUIRE(edgecase_free.to_string_status() == "Status:\tFree");

        Robot busy("NA", "Busy", "NA", "NA", "NA");
        Robot edgecase_busy("NA", "busy", "NA", "NA", "NA");
        REQUIRE(busy.to_string_status() == "Status:\tBusy");
        REQUIRE(edgecase_busy.to_string_status() == "Status:\tBusy");
    }
    
    SECTION("Concentration: Robot Size") { 
        // COMING SOON: needs to be updated
        Robot small("NA", "NA", "Small", "NA", "NA");
        Robot edgecase_small("NA", "NA", "small", "NA", "NA");
        REQUIRE(small.to_string_size() == "Size:\tSmall");
        REQUIRE(edgecase_small.to_string_size() == "Size:\tSmall");

        Robot med("NA", "NA", "Medium", "NA", "NA");
        Robot edgecase_med("NA", "NA", "medium", "NA", "NA");
        REQUIRE(med.to_string_size() == "Size:\tMedium");
        REQUIRE(edgecase_med.to_string_size() == "Size:\tMedium");

        Robot large("NA", "NA", "Large", "NA", "NA");
        Robot edgecase_large("NA", "NA", "large", "NA", "NA");
        REQUIRE(large.to_string_size() == "Size:\tLarge");
        REQUIRE(edgecase_large.to_string_size() == "Size:\tLarge");
    }

    SECTION("Concentration: Robot Type") { 
        // COMING SOON: needs to be updated
        Robot mop("NA", "NA", "NA", "Mop", "NA");
        Robot edgecase_mop("NA", "NA", "NA", "mop", "NA");
        REQUIRE(mop.to_string_type() == "Type:\tMop");
        REQUIRE(edgecase_mop.to_string_type() == "Type:\tMop");

        Robot vac("NA", "NA", "NA", "Vac", "NA");
        Robot edgecase_vac("NA", "NA", "NA", "vac", "NA");
        REQUIRE(vac.to_string_type() == "Type:\tVaccuum");
        REQUIRE(edgecase_vac.to_string_type() == "Type:\tVaccuum");

        Robot scrub("NA", "NA", "NA", "Scrub", "NA");
        Robot edgecase_scrub("NA", "NA", "NA", "scrub", "NA");
        REQUIRE(scrub.to_string_type() == "Type:\tScrub");
        REQUIRE(edgecase_scrub.to_string_type() == "Type:\tScrub");
    }

    SECTION("Concentration: Robot Room Assignment") { 
        // COMING SOON: needs to be updated
        Robot cleaner("0", "Free", "Small", "Mop", "NA");
        REQUIRE(cleaner.get_room() == "NA");
        cleaner.set_room("3");
        REQUIRE(cleaner.get_room() == "3");
        REQUIRE(cleaner.to_string_status() == "Status:\tBusy");
    }
        
}