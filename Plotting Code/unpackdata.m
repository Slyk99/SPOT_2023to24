%% Unpack Data
function result = unpackdata(dataClass)
%% Time
result.time = dataClass.Time_s;
%% Red Data
result.actual_states = [dataClass.RED_Px_m, dataClass.RED_Py_m, dataClass.RED_Rz_rad];
result.desired_states = [dataClass.CustomUserData48, dataClass.CustomUserData49, dataClass.CustomUserData50];
effort = [dataClass.RED_Fx_Sat_N,dataClass.RED_Fy_Sat_N,dataClass.RED_Tz_Sat_Nm];
result.effort = effort*0.01;
end