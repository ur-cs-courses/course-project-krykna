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
        Robot bot("0", "Free", "Small", "Vac", "3");
        REQUIRE(bot.to_string_status() == "Status:\tFree");
        REQUIRE(bot.to_string_size() == "Size:\tSmall");
        REQUIRE(bot.to_string_type() == "Type:\tVaccuum");
        REQUIRE(bot.get_room() == "3");
    }

    SECTION("Concentration: Robot Constructor Edge Case") {
        Robot bot("0", "free", "small", "vac", "3");
        REQUIRE(bot.to_string_status() == "Status:\tFree");
        REQUIRE(bot.to_string_size() == "Size:\tSmall");
        REQUIRE(bot.to_string_type() == "Type:\tVaccuum");
        REQUIRE(bot.get_room() == "3");
    }

    SECTION("Concentration: Robot Status") { 
        SECTION("Normal Cases") {
            Robot free("NA", "Free", "Small", "Mop", "NA");
            Robot busy("NA", "Busy", "Small", "Mop", "NA");
            REQUIRE(free.to_string_status() == "Status:\tFree");
            REQUIRE(busy.to_string_status() == "Status:\tBusy");
        }

        SECTION("Edge Cases") {
            Robot edgecase_free("NA", "free", "Small", "Mop", "NA");
            Robot edgecase_busy("NA", "busy", "Small", "Mop", "NA");
            REQUIRE(edgecase_free.to_string_status() == "Status:\tFree");
            REQUIRE(edgecase_busy.to_string_status() == "Status:\tBusy");
        }
    }
    
    SECTION("Concentration: Robot Size") { 
        SECTION("Normal Cases") {
            Robot small("NA", "Free", "Small", "Mop", "NA");
            Robot med("NA", "Free", "Medium", "Mop", "NA");
            Robot large("NA", "Free", "Large", "Mop", "NA");
            REQUIRE(small.to_string_size() == "Size:\tSmall");
            REQUIRE(med.to_string_size() == "Size:\tMedium");
            REQUIRE(large.to_string_size() == "Size:\tLarge");
        }

        SECTION("Edge Cases") {
            Robot edgecase_small("NA", "Free", "small", "Mop", "NA");
            Robot edgecase_med("NA", "Free", "medium", "Mop", "NA");
            Robot edgecase_large("NA", "Free", "large", "Mop", "NA");
            REQUIRE(edgecase_small.to_string_size() == "Size:\tSmall");
            REQUIRE(edgecase_med.to_string_size() == "Size:\tMedium");
            REQUIRE(edgecase_large.to_string_size() == "Size:\tLarge");
        }
    }

    SECTION("Concentration: Robot Type") { 
        SECTION("Normal Cases") {
            Robot mop("NA", "Free", "Small", "Mop", "NA");
            Robot vac("NA", "Free", "Small", "Vac", "NA");
            Robot scrub("NA", "Free", "Small", "Scrub", "NA");
            REQUIRE(mop.to_string_type() == "Type:\tMop");
            REQUIRE(vac.to_string_type() == "Type:\tVaccuum");
            REQUIRE(scrub.to_string_type() == "Type:\tScrub");
        }

        SECTION("Edge Cases") {
            Robot edgecase_mop("NA", "Free", "Small", "mop", "NA");
            Robot edgecase_vac("NA", "Free", "Small", "vac", "NA");
            Robot edgecase_scrub("NA", "Free", "Small", "scrub", "NA");
            REQUIRE(edgecase_mop.to_string_type() == "Type:\tMop");
            REQUIRE(edgecase_vac.to_string_type() == "Type:\tVaccuum");
            REQUIRE(edgecase_scrub.to_string_type() == "Type:\tScrub");
        }
    }

    SECTION("Concentration: Robot Room Assignment") { 
        Robot cleaner("0", "Free", "Small", "Mop", "NA");
        REQUIRE(cleaner.get_room() == "NA");
        cleaner.set_room("3");
        REQUIRE(cleaner.get_room() == "3");
        REQUIRE(cleaner.to_string_status() == "Status:\tBusy");
    }
        
}