import unittest
import {{cookiecutter.python_package_name}}



class TestBuildConfig(unittest.TestCase):
    
    def test_version(self):
        config = {{cookiecutter.python_package_name}}.BuildConfiguration
        self.assertEqual(config.VERSION_MAJOR, 0)
        self.assertEqual(config.VERSION_MINOR, 1)
        self.assertEqual(config.VERSION_PATCH, 0)

