//
// Created by josur on 10/06/2025.
//

#include "Level_core.hpp"

Level_core::Level_core(const string &level_json_path) {

    ifstream level_json_file(level_json_path);

    if (!level_json_file.is_open()) {
        throw std::runtime_error("Could not open JSON file at: " + level_json_path);
    }

    basic_json<> level_data = json::parse(level_json_file);

    cout << "json parsed, it works !" << endl;

    this->number_of_checkpoints = level_data.at("number_of_checkpoints");
    this->number_of_towers = level_data.at("number_of_towers");
    this->number_of_enemies = level_data.at("number_of_enemies");
    this->number_of_waves = level_data.at("number_of_waves");

    cout << "Basic info recovered" << endl;

    this->checkpoints_coordinates.reserve(number_of_checkpoints);
    this->towers_coordinates.reserve(number_of_towers);
    this->waves.reserve(number_of_waves);

    cout << "Vectors reservation worked" << endl;

    for (int i = 0; i < number_of_checkpoints; i++) {
        basic_json<> checkpoint_coordinates = level_data.at("checkpoints_coordinates").at(to_string(i));
        array<int, 2> coordinates = {checkpoint_coordinates.at("x"), checkpoint_coordinates.at("z")};
        this->checkpoints_coordinates.push_back(coordinates);
    }

    cout << "Checkpoints coordinates recovered" << endl;

    for (int i = 0; i < number_of_towers; i++) {
        basic_json<> turret_coordinates = level_data.at("towers_coordinates").at(to_string(i));
        array<int, 2> coordinates = {turret_coordinates.at("x"), turret_coordinates.at("z")};
        this->towers_coordinates.push_back(coordinates);
    }

    cout << "Turret coordinates recovered" << endl;

    for (int i = 0; i < number_of_waves; i++) {
        basic_json<> wave_data = level_data.at("wave_" + to_string(i + 1));

        level_wave_info wave;

        wave.number_of_enemies = wave_data.at("spawn_amount");
        wave.spawn_interval = wave_data.at("spawn_interval");
        wave.spawn_order.reserve(wave.number_of_enemies);

        for (int j = 0; j < wave.number_of_enemies; j++) {
            wave.spawn_order.push_back(wave_data.at("spawn_order").at(to_string(j + 1)));
        }
        this->waves.push_back(wave);
    }
    cout << "Info got from json, level_core class fully instantiated" << endl;
}