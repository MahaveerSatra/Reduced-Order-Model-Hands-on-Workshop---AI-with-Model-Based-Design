function timetables = segregatePMSMData(filename)
% Define the Excel file name

% Read the data from the Excel file
opts = detectImportOptions(filename);
data_og = readtable(filename, opts);

% Remove the Torque variable as it is not an input or output and ensure the
% order is maintained for seamless data import
data = data_og(:,["ambient","coolant","u_d","u_q","motor_speed","i_d","i_q","pm","stator_yoke","stator_tooth","stator_winding","profile_id"]);
clear data_og;


% Extract unique profile_ids
unique_ids = unique(data.profile_id);

% Initialize a cell array to hold all timetables
timetables = cell(length(unique_ids), 1);

% Loop through each unique profile_id
for i = 1:length(unique_ids)
    profile_ids = unique_ids(i);

    % Filter data for the current profile_id
    filtered_data = data(data.profile_id == profile_ids, :);

    % Create a timetable with a time vector based on the frequency of 2 Hz
    timetable_data = table2timetable(filtered_data(:, 1:end-1),"SampleRate",2); % Exclude profile_id column

    % Store the timetable in the cell array
    timetables{i} = timetable_data;

end

% Optionally, you can save the cell array to a .mat file
% save([filename(1:end-4),'.mat'], 'timetables');  % Renaming by removing the .csv and adding .mat file, but keeping the same name.