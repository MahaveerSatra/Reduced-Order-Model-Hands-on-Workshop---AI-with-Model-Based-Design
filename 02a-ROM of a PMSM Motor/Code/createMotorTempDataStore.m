function ds=createMotorTempDataStore(tt_predictors,tt_responses,profile_id)
ttx=[tt_predictors,table(profile_id)];

numprofiles=numel(unique(ttx.profile_id));
profiles=[unique(ttx.profile_id)];
for i=1:numprofiles
   filename=".\MotorTemp\" + num2str(profiles(i)) +".csv";
   g=find(ttx.profile_id==profiles(i));
   temp=[ttx(g,:),tt_responses(g,1)];
   writetable(temp,filename);

end
