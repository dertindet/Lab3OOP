#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <cassert>
#include "MusicCollection.h"
#include "Song.h"
#include "InstrumentalWork.h"

class TestCases {
public:
    void runAllTests() {
        Test1_AddComposition();
        Test2_GetCompositions();
        Test3_SongGetters();
        Test4_InstrumentalWorkGetters();
        Test6_RemoveComposition_Invalid();
        Test5_RemoveComposition_Valid();
        Test7_BoundaryIndex();
        Test8_ExceptionHandling();
        Test9_SongAndInstrumentalInComposition();
    }

    static void EqTest(const std::string& test_name, bool condition) {
        if (condition) {
            std::cout << test_name << ": Passed\n";
        }
        else {
            std::cout << test_name << ": Failed\n";
        }
    }

    static void Test1_AddComposition() {
        std::string test_name = "Test 1: addComposition";
        MusicCollection collection;

        collection.addComposition(new Song("Imagine", 183, "John Lennon"));
        collection.addComposition(new InstrumentalWork("Moonlight Sonata", 900, "Beethoven"));

        EqTest(test_name, collection.getCompositions().size() == 2);
    }

    static void Test2_GetCompositions() {
        std::string test_name = "Test 2: getCompositions";
        MusicCollection collection;
        EqTest(test_name + " (empty)", collection.getCompositions().empty());

        //Song song("Imagine", 183, "John Lennon");
        collection.addComposition(new Song("Imagine", 183, "John Lennon"));
        //collection.addComposition(&song);
        EqTest(test_name + " (one element)", collection.getCompositions().size() == 1);
    }

    static void Test3_SongGetters() {
        std::string test_name = "Test 3: Song getters";
        Song song("Imagine", 183, "John Lennon");

        bool passed = (song.getTitle() == "Imagine") &&
            (song.getDuration() == 183) &&
            (song.getVocalist() == "John Lennon");

        EqTest(test_name, passed);
    }

    static void Test4_InstrumentalWorkGetters() {
        std::string test_name = "Test 4: InstrumentalWork getters";
        InstrumentalWork instrumental("Moonlight Sonata", 900, "Beethoven");

        bool passed = (instrumental.getTitle() == "Moonlight Sonata") &&
            (instrumental.getDuration() == 900) &&
            (instrumental.getComposer() == "Beethoven");

        EqTest(test_name, passed);
    }

    static void Test5_RemoveComposition_Valid() {
        std::string test_name = "Test 5: removeComposition (valid index)";
        MusicCollection collection;
        Song song("Imagine", 183, "John Lennon");

        //collection.addComposition(&song);
        collection.addComposition(new Song("Imagine", 183, "John Lennon"));
        bool result = collection.removeComposition(0);

        EqTest(test_name, result && collection.getCompositions().empty());
    }

    static void Test6_RemoveComposition_Invalid() {
        std::string test_name = "Test 6: removeComposition (invalid index)";
        MusicCollection collection;
        Song song("Imagine", 183, "John Lennon");

        //collection.addComposition(&song);
        collection.addComposition(new Song("Imagine", 183, "John Lennon"));
        bool result = collection.removeComposition(10);

        EqTest(test_name, !result && collection.getCompositions().size() == 1);
    }

    static void Test7_BoundaryIndex() {
        std::string test_name = "Test 7: Boundary index";
        MusicCollection collection;
        //Song song("Imagine", 183, "John Lennon");
        //InstrumentalWork instrumental("Moonlight Sonata", 900, "Beethoven");

        //collection.addComposition(&song);
        //collection.addComposition(&instrumental);
        collection.addComposition(new Song("Imagine", 183, "John Lennon"));
        collection.addComposition(new InstrumentalWork("Moonlight Sonata", 900, "Beethoven"));
        bool result = collection.removeComposition(1);

        EqTest(test_name, result && collection.getCompositions().size() == 1);
    }
    
    static void Test8_ExceptionHandling() {
        std::string test_name = "Test 8: Exception handling";
        try {
            MusicCollection collection;
            collection.getCompositions().at(10);
            EqTest(test_name, false); 
        }
        catch (const std::out_of_range& e) {
            EqTest(test_name, true);
        }
    }
    static void Test9_SongAndInstrumentalInComposition() {
        std::string test_name = "Test 9: song_and_instrumental_in_collection";

        MusicCollection collection;
        collection.addComposition(new Song("Imagine", 183, "John Lennon"));
        collection.addComposition(new InstrumentalWork("Moonlight Sonata", 900, "Beethoven"));


        const auto& compositions = collection.getCompositions();

        bool passed = dynamic_cast<Song*>(compositions[0]) != nullptr &&
            dynamic_cast<InstrumentalWork*>(compositions[1]) != nullptr;

        EqTest(test_name, passed);

 
    }
};