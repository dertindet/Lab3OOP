import unittest
from song import Song
from instrumental_work import InstrumentalWork
from music_collection import MusicCollection
from exception import MyIndexOutOfBoundsException, MyInvalidChoiceException

class TestMusicCollection(unittest.TestCase):

    def setUp(self):
        self.collection = MusicCollection()
        self.song = Song("Imagine", 183, "John Lennon")
        self.instrumental = InstrumentalWork("Moonlight Sonata", 900, "Beethoven")

    # Positive Test Cases
    def test_add_composition(self):
        self.collection.add_composition(self.song)
        self.collection.add_composition(self.instrumental)
        self.assertEqual(len(self.collection.get_compositions()), 2, "Test add_composition failed")
        
    def test_get_compositions(self):
        self.assertEqual(self.collection.get_compositions(), [], "Test get_compositions failed")

        self.collection.add_composition(self.song)
        self.collection.add_composition(self.instrumental)
        compositions = self.collection.get_compositions()
        
        self.assertEqual(len(compositions), 2, "Test get_compositions failed")

        self.assertIs(compositions[0], self.song, "Test get_compositions failed")
        self.assertIs(compositions[1], self.instrumental, "Test get_compositions failed")

    def test_remove_composition_valid_index(self):
        self.collection.add_composition(self.song)
        result = self.collection.remove_composition(0)
        self.assertTrue(result)
        self.assertEqual(len(self.collection.get_compositions()), 0, "Test remove_composition_valid_index failed")

    # Negative Test Cases
    def test_remove_composition_invalid_index(self):
        self.collection.add_composition(self.song)
        result = self.collection.remove_composition(10)
        self.assertFalse(result, "Test remove_composition_invalid_index failed")
        self.assertEqual(len(self.collection.get_compositions()), 1, "Test remove_composition_invalid_index failed")

    # Boundary Test Cases
    def test_remove_composition_boundary_index(self):
        self.collection.add_composition(self.song)
        self.collection.add_composition(self.instrumental)
        result = self.collection.remove_composition(1)  # Last valid index
        self.assertTrue(result, "Test remove_composition_boundary_index failed")
        self.assertEqual(len(self.collection.get_compositions()), 1, "Test remove_composition_boundary_index failed")

    # Exception Handling Test Cases
    def test_remove_composition_out_of_bounds_exception(self):
        with self.assertRaises(IndexError):
            self.collection.get_compositions()[10]

    # Relationship Between Classes Test Cases
    def test_song_and_instrumental_in_collection(self):
        self.collection.add_composition(self.song)
        self.collection.add_composition(self.instrumental)
        compositions = self.collection.get_compositions()
        self.assertIsInstance(compositions[0], Song, "Test song_and_instrumental_in_collection failed")
        self.assertIsInstance(compositions[1], InstrumentalWork, "Test song_and_instrumental_in_collection failed")

class TestSong(unittest.TestCase):

    def setUp(self):
        self.song = Song("Imagine", 183, "John Lennon")

    def test_get_title(self):
        self.assertEqual(self.song.get_title(), "Imagine", "Test get_title song failed")

    def test_get_duration(self):
        self.assertEqual(self.song.get_duration(), 183, "Test get_duration song failed")

    def test_get_vocalist(self):
        self.assertEqual(self.song.get_vocalist(), "John Lennon", "Test get_vocalist song failed")

class TestInstrumentalWork(unittest.TestCase):

    def setUp(self):
        self.instrumental = InstrumentalWork("Moonlight Sonata", 900, "Beethoven")

    def test_get_title(self):
        self.assertEqual(self.instrumental.get_title(), "Moonlight Sonata", "Test get_title instrumental work failed")

    def test_get_duration(self):
        self.assertEqual(self.instrumental.get_duration(), 900, "Test get_duration instrumental work failed")

    def test_get_composer(self):
        self.assertEqual(self.instrumental.get_composer(), "Beethoven", "Test get_vocalist instrumental work failed")




