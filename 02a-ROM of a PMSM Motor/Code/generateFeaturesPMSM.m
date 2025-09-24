function PMSM_Features_TimeTables = generateFeaturesPMSM(PMSM_TimeTables)

for i = 1:length(PMSM_TimeTables)

    featureTimeTable = compute_umag_imag_power(PMSM_TimeTables{i});

    



end

end


% Compute Features
% Compute magnitude of voltage and current, and active power.
function featureTimeTable = compute_umag_imag_power(tt)
    % Calcuate Imaginary and Imaginery power
    umag = sqrt(tt.u_d.^2 + tt.u_q.^2);
    umag = umag - mean(umag);
    
    imag = sqrt(tt.i_d.^2 + tt.i_q.^2);
    imag = imag - mean(imag);
    
    P = 1.5*umag.*imag;
    
    % Create a timetable with a time vector based on the frequency of 2 Hz
    featureTimeTable = array2timetable([umag,imag,P],"VariableNames",{'u_mag','i_mag','power'},"SampleRate",2);
end